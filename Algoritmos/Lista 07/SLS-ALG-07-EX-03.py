chaves = []
def buscaReversa(dicionario, valor):
    for nome, numero in dicionario.items():
        if numero == valor:
            chaves.append(nome)
    return chaves

def main():
    dicionario = {'Felipe': 3, 'Maria': 2, 'Victor': 3, 'Ana': 1}
    valor = int(input("Digite o valor: "))
    chaves_encontradas = buscaReversa(dicionario, valor)

    print("Chave(s) mapeada(s) para o valor digitado:", chaves_encontradas)

main()