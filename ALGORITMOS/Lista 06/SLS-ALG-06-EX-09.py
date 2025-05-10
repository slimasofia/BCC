lista = []
i = 0

while True:
    n = input("Digite um número (ou enter para sair): ")
    if n == "":
        break
    else:
        n = int(n)
        lista.append(n)
print(lista)

media = sum(lista)/len(lista)
valores_abaixo = []
valores_acima = []

for i in lista:
    if i < media:
        valores_abaixo.append(i)
    elif i > media:
        valores_acima.append(i)

print("Média:", media)
print("Valores abaixo da média:", valores_abaixo)
print("Valores acima da média:", valores_acima)
