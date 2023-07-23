x = float(input("Digite um número: "))
raiz = x/2

while (raiz * raiz - x) > (10**-12):
    raiz = (raiz + x/raiz)/2
print("A raiz quadrada do número escolhido é: ", raiz)
