def countRange(lista, min, max):
    elementos = []
    for i in lista:
        if i >= min and i < max:
            elementos.append(i)
    quantidade = len(elementos)
    return quantidade

def main():
    lista = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    min = int(input("Digite o valor mínimo: "))
    max = int(input("Digite o valor máximo: "))
    quantidade = countRange(lista, min, max)
    print("Quantidade de elementos no intervalo:", quantidade)

main()
