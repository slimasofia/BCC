taxa_fixa = 4.00
taxa_metro = 0.25 / 140

def calcular_corrida(distancia):
    valor_total = taxa_fixa + ((taxa_metro * distancia) * 1000)
    return valor_total

distancia = float(input("Digite a distância em quilômetros: "))
valor_total = calcular_corrida(distancia)
print("O valor total da corrida é de: R$ {:.2f}".format(valor_total))


