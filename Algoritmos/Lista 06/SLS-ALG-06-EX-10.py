def lista_de_itens(lista):
    n = len(lista)
    if n == 1:
        return str(lista)
    elif n == 2:
        return str(lista[0]) + " e " + str(lista[1])
    else:
        frase=""
        for i in range(n):
            if i < n-2:
                frase = frase + lista[i] + ", "
            if i == (n-2):
                frase = frase + lista[i] + " e "+ lista[n-1]
        return frase
    
def main():
    lista = []
    while(True):
        palavra = input("digite um palavra: ")
        if(palavra == ""):
            break
        lista.append(palavra)
    resposta = lista_de_itens(lista)
    print(resposta)

main()
