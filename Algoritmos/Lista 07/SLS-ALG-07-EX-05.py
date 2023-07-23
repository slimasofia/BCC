def sao_anagramas(palavra1, palavra2):
    if len(palavra1) != len(palavra2):
        return False

    contagem1 = {}
    contagem2 = {}

    for letra in palavra1:
        contagem1[letra] = contagem1.get(letra, 0) + 1

    for letra in palavra2:
        contagem2[letra] = contagem2.get(letra, 0) + 1
    print(contagem1)
    print(contagem2)
    return contagem1 == contagem2

palavra1 = input("Digite a primeira palavra: ")
palavra2 = input("Digite a segunda palavra: ")

if sao_anagramas(palavra1, palavra2):
    print("As palavras são anagramas.")
    
else:
    print("As palavras não são anagramas.")
