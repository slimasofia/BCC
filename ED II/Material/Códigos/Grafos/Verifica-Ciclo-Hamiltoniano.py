QUANT_VERTICES = 4

grafo = [[0, 1, 1, 1], [1, 0, 1, 0], [1, 1, 0, 1], [1, 0, 1, 0]]

def ehSeguro(v, caminho, pos):
    if grafo[caminho[pos - 1]][v] == 0:
        return False
    if v in caminho:
        return False
    return True

def cicloHamiltonianoAux(caminho, pos):
    if pos == QUANT_VERTICES:
        return grafo[caminho[pos - 1]][caminho[0]] == 1
    
    for v in range(QUANT_VERTICES):
        if ehSeguro(v, caminho, pos):
            caminho[pos] = v
            if cicloHamiltonianoAux(caminho, pos + 1):
                return True
            caminho[pos] = -1
    return False

def cicloHamiltoniano(inicio):
    caminho = [-1] * QUANT_VERTICES
    caminho[0] = inicio

    if cicloHamiltonianoAux(caminho, 1):
        print("Ciclo Hamiltoniano encontrado:", caminho + [inicio])
    else:
        print("Não existe ciclo Hamiltoniano.")

cicloHamiltoniano(0)
cicloHamiltoniano(1)
cicloHamiltoniano(2)
cicloHamiltoniano(3)