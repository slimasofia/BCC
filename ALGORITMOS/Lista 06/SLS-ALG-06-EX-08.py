def retorna_palavra(frase):
    pontuacao = [".", ",", ":", ";", "!", "?"]
    for p in pontuacao:
        frase = frase.replace(p," ")
    frase = frase.split()
    return frase

def main():
    frase = input("Digite um texto: ")
    x = retorna_palavra(frase)
    print(x)

main()