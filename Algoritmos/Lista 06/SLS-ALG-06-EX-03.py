def remover_extremos(lista, n):
    lista_ordenada = sorted(lista)
    
    if len(lista_ordenada) < 4:
        print("Erro: insira 4 ou mais valores. ")
        return None

    del lista_ordenada[:n]
    del lista_ordenada[-n:]
    return lista_ordenada

def main():
    lista = []
    while True:
        n = int(input("Digite um número n: "))
        if n == 0:
            break
        lista.append(n)

    lista_sem_extremos = remover_extremos(lista, 2)
    if lista_sem_extremos is not None:
        print("Lista sem os extremos:", lista_sem_extremos)
        print("Lista original:", lista)

main()