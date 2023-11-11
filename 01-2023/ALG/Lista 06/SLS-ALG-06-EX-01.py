lista = []
   
while True:
    inteiro = int(input("Digite um número inteiro: "))

    if inteiro == 0:
        break
    elif inteiro != 0:
        lista.append(inteiro)
        lista_ordenada = sorted(lista)

print(lista_ordenada) 
        