from collections import deque

def bfs(grafo, inicio):
    visitado = [False] * len(grafo)
    fila = deque([inicio])
    
    visitado[inicio] = True
    
    while fila:
        vertice = fila.popleft()
        print(f"Visitado {vertice}")
        
        for i, adjacente in enumerate(grafo[vertice]):
            if adjacente and not visitado[i]:
                fila.append(i)
                visitado[i] = True

grafo = [[0, 1, 1, 0], [1, 0, 1, 1], [1, 1, 0, 1], [0, 1, 1, 0]]

bfs(grafo, 0) # Altere o segundo parâmetro!