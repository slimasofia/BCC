lista = []
while True:
    p = input("Digite uma p (enter para sair): ")
    if p == "":
        break
    else:
        lista.append(p)

palavras = []
for p in lista:
    if p not in palavras:
        palavras.append(p)
        print(p)
