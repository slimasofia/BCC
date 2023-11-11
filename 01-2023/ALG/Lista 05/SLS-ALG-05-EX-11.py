import random

def gerar_senha():

    i = 0
    tamanho_senha = random.randint(7, 10)
    senha = ""

    while i != tamanho_senha:
        i = i + 1

        n_caractere = random.randint(33, 126)
        c = chr(n_caractere)
        senha += c
    return senha

senha_aleatoria = gerar_senha()
print(senha_aleatoria)  
