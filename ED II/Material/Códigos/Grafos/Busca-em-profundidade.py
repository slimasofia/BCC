def dfs(grafo, inicio, visitado=None):
    if visitado is None:
        visitado = [False] * len(grafo)
        
    visitado[inicio] = True
    print(f"Visitado {inicio}")
    
    for i, adjacente in enumerate(grafo[inicio]):
        if adjacente and not visitado[i]:
            dfs(grafo, i, visitado)

grafo = [[0, 1, 1, 0], [1, 0, 1, 1], [1, 1, 0, 1], [0, 1, 1, 0]]

dfs(grafo, 2) # Altere o segundo parâmetro!