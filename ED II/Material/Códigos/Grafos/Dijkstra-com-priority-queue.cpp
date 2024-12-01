#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <queue>

#define INF INT_MAX
#define V 5

using namespace std;

string cidades[V] = {"Blu", "Indaial", "Gaspar", "Ilhota", "Itajaí"};

struct Aresta {
    unsigned int vertice;
    unsigned int peso;
    
    // Definindo o operador < para que a priority_queue organize pelo menor peso (neste caso modelado como se fosse a distância)
    bool operator>(const Aresta& outra) const {
        return peso > outra.peso;
    }
};

void dijkstra(unsigned int grafo[V][V], const string& cidade) {
    unsigned int origem;
    for (unsigned int i = 0; i < V; i++)
        if (cidade == cidades[i]) {
            origem = i;
            break;
        }

    unsigned int dist[V];
    fill(dist, dist + V, INF);
    dist[origem] = 0;

    // Usando priority_queue para implementar a fila de prioridade
    priority_queue<Aresta, vector<Aresta>, greater<Aresta>> pq;
    pq.push(Aresta{origem, 0});

    while (!pq.empty()) {
        Aresta min = pq.top();
        pq.pop();
        unsigned int u = min.vertice;

        for (unsigned int v = 0; v < V; v++) {
            if (grafo[u][v] && dist[u] != INF && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
                pq.push(Aresta{v, dist[v]});
            }
        }
    }

    cout << "Vértice\t\tDistância da Origem (" << cidades[origem] << ")\n";
    for (unsigned int i = 0; i < V; i++)
        cout << cidades[i] << "\t\t" << dist[i] << "\n";
}

int main() {
    unsigned int grafo[V][V] = { {0, 15, 20, 0, 0}, {15, 0, 0, 40, 0}, {20, 0, 0, 12, 30}, {0, 40, 12, 0, 10}, {0, 0, 30, 10, 0} };
    dijkstra(grafo, "Blu");
    return 0;
}