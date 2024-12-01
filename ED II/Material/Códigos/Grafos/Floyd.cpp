#include <iostream>
#include <climits>
#include <vector>
#include <string>

#define V 5
#define INF INT_MAX

using namespace std;

string cidades[V] = {"Blu", "Indaial", "Gaspar", "Ilhota", "Itajaí"};

void floydWarshall(const vector<vector<int>>& grafo) {
    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (grafo[i][j] == 0 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = grafo[i][j];
        }
    }

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    cout << "\t";
    for (int i = 0; i < V; i++)
        cout << cidades[i] << "\t";
    
    cout << "\n";

    for (int i = 0; i < V; i++) {
        cout << cidades[i] << "\t";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> grafo = { {0, 15, 20, 0, 0}, {15, 0, 0, 40, 0}, {20, 0, 0, 12, 30}, {0, 40, 12, 0, 10}, {0, 0, 30, 10, 0} };
    floydWarshall(grafo);
    return 0;
}