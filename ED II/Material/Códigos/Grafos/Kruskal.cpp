#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Aresta {
public:
    int origem, destino, peso;
    Aresta(int o, int d, int p) : origem(o), destino(d), peso(p) {}
};

bool compararArestas(Aresta a, Aresta b) {
    return a.peso < b.peso;
}

class Grafo {
    int V;
    vector<Aresta> arestas;

public:
    Grafo(int V) : V(V) {}

    void adicionarAresta(int origem, int destino, int peso) {
        arestas.push_back(Aresta(origem, destino, peso));
    }

    int encontrarPai(int v, vector<int>& pai) {
        if (pai[v] == v) return v;
        return pai[v] = encontrarPai(pai[v], pai);
    }

    void unir(int u, int v, vector<int>& pai, vector<int>& rank) {
        int paiU = encontrarPai(u, pai);
        int paiV = encontrarPai(v, pai);
        if (rank[paiU] < rank[paiV])
            pai[paiU] = paiV;
        else if (rank[paiU] > rank[paiV])
            pai[paiV] = paiU;
        else {
            pai[paiV] = paiU;
            rank[paiU]++;
        }
    }

    void kruskal() {
        sort(arestas.begin(), arestas.end(), compararArestas);

        vector<int> pai(V), rank(V, 0);
        for (int i = 0; i < V; i++) pai[i] = i;

        int custoTotal = 0;
        cout << "Arestas da MST:\n";
        for (auto& aresta : arestas) {
            int u = aresta.origem;
            int v = aresta.destino;
            int peso = aresta.peso;

            if (encontrarPai(u, pai) != encontrarPai(v, pai)) {
                cout << u << " - " << v << " com custo " << peso << "\n";
                custoTotal += peso;
                unir(u, v, pai, rank);
            }
        }
        cout << "Custo total: " << custoTotal << endl;
    }
};

int main() {
    Grafo grafo(5);
    grafo.adicionarAresta(0, 1, 2);
    grafo.adicionarAresta(0, 3, 6);
    grafo.adicionarAresta(1, 2, 3);
    grafo.adicionarAresta(1, 3, 8);
    grafo.adicionarAresta(1, 4, 5);
    grafo.adicionarAresta(2, 4, 7);
    grafo.adicionarAresta(3, 4, 9);

    grafo.kruskal();
    return 0;
}