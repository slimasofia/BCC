import random
def gerar_cartela():
    cartela_bingo = {'B': [], 'I': [], 'N': [], 'G': [], 'O': []}

    for x in range(5):
        cartela_bingo['B'].append(random.randint(1, 15))
        cartela_bingo['I'].append(random.randint(16, 30))
        cartela_bingo['N'].append(random.randint(31, 45))
        cartela_bingo['G'].append(random.randint(46, 60))
        cartela_bingo['O'].append(random.randint(61, 75))
    return cartela_bingo

def exibir_cartela_bingo(cartela):
    print("  B   I   N   G   O")
    for i in range(5):
        linha = ""
        for letra in cartela:
            linha += str(cartela[letra][i]).rjust(3) + " "
        print(linha)

cartela = gerar_cartela()
exibir_cartela_bingo(cartela) 

sorteados = []

for r in range(5):
    num = random.randint(1, 75)
    sorteados.append(num)
print("Sorteados: ", sorteados)


for letra, lista in cartela.items():
    for valor in lista:
        if valor in sorteados:
           index = sorteados.index(valor)
           sorteados[index] = 0
print(sorteados)



