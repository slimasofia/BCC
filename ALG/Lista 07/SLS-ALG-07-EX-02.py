M = {2, 4, 5, 9}
N = {2, 4, 11, 12}

def diferenca_simetrica(M, N):
    lista = []
    diferenca_simetrica = M.symmetric_difference(N)
    for x in diferenca_simetrica:
        lista.append(x)
    return lista

diferenca = diferenca_simetrica(M, N)
print(diferenca)
