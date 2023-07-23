produtos = [4.95, 9.95, 14.95, 19.95, 24.95]
desconto = 60

for valor in produtos:
    valor_desconto = valor * (desconto/100)
    novo_valor = valor - valor_desconto
    print(f"Preço original: R$ {valor:.2f} | Desconto: {desconto}% | Novo valor com desconto: R$ {novo_valor:.2f}")
