troco = int(input("Digite o troco em centavos: "))

v_50 = troco // 50
troco %= 50

v_25 = troco // 25
troco %= 25

v_10 = troco // 10
troco %= 10

v_5 = troco // 5
troco %= 5

v_1 = troco // 1

print("Moedas de 50 centavos:", v_50)
print("Moedas de 25 centavos:", v_25)
print("Moedas de 10 centavos:", v_10)
print("Moedas de 5 centavos:", v_5)
print("Moedas de 1 centavo:", v_1)
