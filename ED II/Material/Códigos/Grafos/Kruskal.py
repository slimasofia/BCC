class Grafo:
    def __init__(self, V):
        self.V = V
        self.arestas = []

    def adicionarAresta(self, u, v, peso):
        self.arestas.append((peso, u, v))

    def encontrarPai(self, pai, v):
        if pai[v] == v:
            return v
        pai[v] = self.encontrarPai(pai, pai[v])
        return pai[v]

    def unir(self, pai, rank, u, v):
        raizU = self.encontrarPai(pai, u)
        raizV = self.encontrarPai(pai, v)
        
        if rank[raizU] < rank[raizV]:
            pai[raizU] = raizV
        elif rank[raizU] > rank[raizV]:
            pai[raizV] = raizU
        else:
            pai[raizV] = raizU
            rank[raizU] += 1

    def kruskal(self):
        self.arestas = sorted(self.arestas)
        pai = list(range(self.V))
        rank = [0] * self.V

        custo_total = 0
        print("Arestas da MST:")
        for peso, u, v in self.arestas:
            if self.encontrarPai(pai, u) != self.encontrarPai(pai, v):
                print(f"{u} - {v} com custo {peso}")
                custo_total += peso
                self.unir(pai, rank, u, v)
        
        print(f"Custo total: {custo_total}")

# Exemplo de uso
grafo = Grafo(5)
grafo.adicionarAresta(0, 1, 2)
grafo.adicionarAresta(0, 3, 6)
grafo.adicionarAresta(1, 2, 3)
grafo.adicionarAresta(1, 3, 8)
grafo.adicionarAresta(1, 4, 5)
grafo.adicionarAresta(2, 4, 7)
grafo.adicionarAresta(3, 4, 9)

grafo.kruskal()
