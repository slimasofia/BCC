INF = float('inf')
V = 5

cidades = ["Blu", "Indaial", "Gaspar", "Ilhota", "Itajaí"]

def floydWarshall(grafo):
    dist = [[INF if grafo[i][j] == 0 and i != j else grafo[i][j] for j in range(V)] for i in range(V)]

    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] != INF and dist[k][j] != INF and dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    print("\t", end="")
    for cidade in cidades:
        print(cidade, end="\t")
    print()
    
    for i in range(V):
        print(cidades[i], end="\t")
        for j in range(V):
            if dist[i][j] == INF:
                print("INF", end="\t")
            else:
                print(dist[i][j], end="\t")
        print()

grafo = [ [0, 15, 20, 0, 0], [15, 0, 0, 40, 0], [20, 0, 0, 12, 30], [0, 40, 12, 0, 10], [0, 0, 30, 10, 0] ]

floydWarshall(grafo)