n = int(input("Digite um número de três algarismos: "))
centena = n // 100
dezena = (n % 100) // 10
unidade = (n % 100) % 10

c_inversa = unidade * 100
d_inversa = dezena * 10
m = c_inversa + d_inversa + centena
print("O inverso do número escolhido é: ", m)
