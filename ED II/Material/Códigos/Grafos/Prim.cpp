#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Função que implementa o algoritmo de Prim para encontrar a Árvore Geradora Mínima (MST)
void prim(int V, vector<vector<pair<int, int>>> &adj) {
    // Vetor que armazena o menor peso para cada vértice
    vector<int> chave(V, INT_MAX);

    // Vetor que armazena o pai de cada vértice na MST
    vector<int> pai(V, -1);

    // Vetor que indica se o vértice já foi incluído na MST
    vector<bool> MST(V, false);
    
    // Fila de prioridade para selecionar o vértice com a menor chave
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Inicializa o vértice inicial (0) com chave 0
    chave[0] = 0;
    pq.push({0, 0});
    
    // Monta a árvore até que todos os vértices sejam processados
    while (!pq.empty()) {
        // Extrai o vértice com a menor chave da fila de prioridade
        int u = pq.top().second;
        pq.pop();
        
        // Verifica se o vértice já foi adicionado à MST para evitar processá-lo novamente
        if (MST[u])
            continue;

        // Marca o vértice como incluído na MST
        MST[u] = true;
        
        // Explora todos os vizinhos do vértice atual
        for (auto &vizinho : adj[u]) {
            // Vértice vizinho
            int v = vizinho.first;

            // Peso da aresta entre u e v
            int peso = vizinho.second;
            
            // Se o vizinho não está na MST e o peso da aresta é menor que o valor atual da chave
            if (!MST[v] && peso < chave[v]) {
                // Atualiza a chave para o menor peso encontrado
                chave[v] = peso;
                // Adiciona o vizinho à fila de prioridade
                pq.push({chave[v], v});
                // Define o vértice atual como pai do vizinho
                pai[v] = u;
            }
        }
    }

    // Calcula e exibe as arestas da MST junto com o custo total
    unsigned int custo = 0;
    for (int i = 1; i < V; ++i) {
        cout << "Aresta: " << pai[i] << " - " << i << " com custo " << chave[i] << "\n";
        // Soma o peso das arestas para calcular o custo total da MST
        custo += chave[i];
    }
    cout << "Custo total: " << custo << endl;
}

int main() {
    // Número de vértices no grafo
    int V = 5;
    
    // Lista de adjacência onde cada elemento é um par (vértice, peso)
    vector<vector<pair<int, int>>> adj(V);
    
    // Adiciona arestas ao grafo com seus respectivos pesos
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});
    
    // Calcula a MST
    prim(V, adj);
    
    return 0;
}