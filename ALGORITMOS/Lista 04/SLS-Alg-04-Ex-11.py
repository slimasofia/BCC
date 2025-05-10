x = input("Digite uma frase: ")
palavra = x.strip().lower().replace(' ', '')


tamanho = len(palavra)


for i in range(tamanho // 2):
    if palavra[1] != palavra[tamanho - 1 -1]:
        print("Não é")
    else:
        print("é")