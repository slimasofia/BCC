lista = []

while True:
    inteiro = int(input("Digite um número inteiro: "))

    if inteiro == 0:
        break
    elif inteiro != 0:
        lista.append(inteiro)
        lista_ordenada = sorted(lista)
        lista_inversa = lista_ordenada.reverse()
print(lista_ordenada) 
        