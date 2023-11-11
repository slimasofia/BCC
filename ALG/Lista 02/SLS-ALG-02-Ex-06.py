n = int(input("Digite um número de quatro algarismos: "))

milhar =  n // 1000
centena = (n % 1000) // 100
dezena = (n % 100) // 10
unidade = n % 10
soma_n = milhar + centena + dezena + unidade
print("A soma dos algarismos digitados é: ", soma_n)