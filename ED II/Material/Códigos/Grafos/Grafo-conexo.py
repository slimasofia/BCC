QUANT_VERTICES = 10

grafo = [[0] * QUANT_VERTICES for _ in range(QUANT_VERTICES)]
visitado = [0] * QUANT_VERTICES

def dfs(v):
    visitado[v] = 1
    for i in range(QUANT_VERTICES):
        if grafo[v][i] and not visitado[i]:
            dfs(i)

def grafo_conexo():
    for i in range(QUANT_VERTICES):
        visitado[i] = 0

    dfs(0)

    for i in range(QUANT_VERTICES):
        if not visitado[i]:
            return False
    return True

def main():
    e = int(input("Digite a quantidade de arestas: "))
    
    for _ in range(e):
        while True:
            print(f"Lembre-se: O seu grafo possui {QUANT_VERTICES} vértices.")
            u, v = map(int, input(f"Digite a aresta (u v), com valores de 0 até {QUANT_VERTICES - 1}: ").split())
            if u < QUANT_VERTICES and v < QUANT_VERTICES:
                break
        grafo[u][v] = grafo[v][u] = 1

    if grafo_conexo():
        print("O grafo é conexo.")
    else:
        print("O grafo não é conexo.")

if __name__ == "__main__":
    main()