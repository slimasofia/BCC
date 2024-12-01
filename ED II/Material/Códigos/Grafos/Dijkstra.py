import sys
import heapq

INF = sys.maxsize
V = 5
cidades = ["Blu", "Indaial", "Gaspar", "Ilhota", "Itajaí"]

class MinHeap:
    def __init__(self):
        self.heap = []

    def insere(self, vertice, peso):
        heapq.heappush(self.heap, (peso, vertice))

    def extraiMin(self):
        return heapq.heappop(self.heap)

def dijkstra(grafo, cidade):
    origem = cidades.index(cidade)
    dist = [INF] * V
    dist[origem] = 0

    heap = MinHeap()
    heap.insere(origem, 0)

    while len(heap.heap) > 0:
        # Extrai o menor elemento
        minElem = heap.extraiMin()
        u = minElem[1]

        for v in range(V):
            if grafo[u][v] and dist[u] != INF and dist[u] + grafo[u][v] < dist[v]:
                dist[v] = dist[u] + grafo[u][v]
                heap.insere(v, dist[v])

    print(f"Vértice\t\tDistância da Origem ({cidade})")
    for i in range(V):
        print(f"{cidades[i]}\t\t{dist[i]}")

grafo = [ [0, 15, 20, 0, 0], [15, 0, 0, 40, 0], [20, 0, 0, 12, 30], [0, 40, 12, 0, 10], [0, 0, 30, 10, 0] ]

dijkstra(grafo, "Blu")