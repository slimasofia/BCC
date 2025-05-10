def dfs_ciclo(grafo, visitado, vertice, pai):
    visitado[vertice] = True
    for i in range(len(grafo)):
        if grafo[vertice][i]:
            if not visitado[i]:
                if dfs_ciclo(grafo, visitado, i, vertice):
                    return True
            elif i != pai:
                return True
    
    return False

def tem_ciclo(grafo):
    visitado = [False] * len(grafo)
    for i in range(len(grafo)):
        if not visitado[i]:
            if dfs_ciclo(grafo, visitado, i, -1):
                return True
    
    return False

grafo = [ [0, 1, 0, 0, 0], [1, 0, 1, 0, 0], [0, 1, 0, 1, 0], [0, 0, 1, 0, 1], [0, 0, 0, 1, 0] ]

if tem_ciclo(grafo):
    print("O grafo tem um ciclo.")
else:
    print("O grafo não tem ciclos.")