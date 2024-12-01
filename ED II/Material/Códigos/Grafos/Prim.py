import heapq

# Função que implementa o algoritmo de Prim para encontrar a Árvore Geradora Mínima (MST)
def prim(V, adj):
    # Vetor que armazena o menor peso para cada vértice
    chave = [float('inf')] * V
    # Vetor que armazena o pai de cada vértice na MST
    pai = [-1] * V
    # Vetor que indica se o vértice já foi incluído na MST
    MST = [False] * V
    
    # Fila de prioridade para selecionar o vértice com a menor chave
    pq = [(0, 0)]  # (peso, vértice)
    chave[0] = 0

    while pq:
        # Extrai o vértice com a menor chave da fila de prioridade
        peso_u, u = heapq.heappop(pq)
        
        # Verifica se o vértice já foi adicionado à MST para evitar processá-lo novamente
        if MST[u]:
            continue
        MST[u] = True  # Marca o vértice como incluído na MST
        
        # Explora todos os vizinhos do vértice atual
        for v, peso in adj[u]:
            # Se o vizinho não está na MST e o peso da aresta é menor que o valor atual da chave
            if not MST[v] and peso < chave[v]:
                # Atualiza a chave para o menor peso encontrado
                chave[v] = peso
                heapq.heappush(pq, (peso, v))
                pai[v] = u  # Define o vértice atual como pai do vizinho

    # Calcula e exibe as arestas da MST junto com o custo total
    custo = 0
    for i in range(1, V):
        print(f"Aresta: {pai[i]} - {i} com custo {chave[i]}")
        custo += chave[i]  # Soma o peso das arestas para calcular o custo total da MST
    print(f"Custo total: {custo}")

# Exemplo de uso
V = 5
# Lista de adjacência onde cada elemento é um par (vértice, peso)
adj = [ [(1, 2), (3, 6)], [(0, 2), (2, 3), (3, 8), (4, 5)], [(1, 3), (4, 7)], [(0, 6), (1, 8)], [(1, 5), (2, 7)] ]

# Calcula a MST
prim(V, adj)