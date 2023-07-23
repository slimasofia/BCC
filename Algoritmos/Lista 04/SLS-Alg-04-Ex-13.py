n = int(input("Digite um número inteiro (maior ou igual a 2): "))

fator = 2
if n < 2:
    print("Erro")
else: 
    while fator <= n:
        if n % fator == 0:
            print(fator)
            n //= fator
        else:
          fator += 1
