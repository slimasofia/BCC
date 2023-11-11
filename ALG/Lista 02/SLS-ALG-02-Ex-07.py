n = int(input("Digite um número de três algarismos: "))
centena = n // 100
dezena = (n % 100) // 10
unidade = (n % 100) % 10
print(f"Esse número tem {centena} centena(s), {dezena} dezena(s) e {unidade} unidade(s)")
