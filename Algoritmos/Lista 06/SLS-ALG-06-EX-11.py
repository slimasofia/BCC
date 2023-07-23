import random
lista = []

while len(lista) < 6:
    numero = random.randint(1, 60)
    if numero not in lista:
        lista.append(numero)

lista.sort()
print(lista)