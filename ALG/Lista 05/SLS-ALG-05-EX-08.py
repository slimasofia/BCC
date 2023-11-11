def corrigir_frase(frase):
    corrigido = frase.capitalize()

    for pontuacao in ['.', '!', '?']:
        corrigido = corrigido.replace(pontuacao + ' ', pontuacao + ' ').capitalize()

    return corrigido

frase = input("Digite uma frase: ")
frase_corrigida = corrigir_frase(frase)
print(frase_corrigida)
