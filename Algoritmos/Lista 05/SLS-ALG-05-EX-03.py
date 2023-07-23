valor_um_item = 10.95

def calcular_envio(itens):
    
    if itens == 1:
        return valor_um_item
    
    elif itens > 1:
        valor_total = 10.95 + 2.95 * itens
        return valor_total
        
    else:
        return 0

itens = float(input("Digite a quantidade de itens: "))
valor_total = calcular_envio(itens)
print("O custo do envio será de: R$ {:.2f}".format(valor_total))