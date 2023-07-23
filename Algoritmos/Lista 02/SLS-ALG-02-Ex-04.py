n1 = int(input("Digite o 1º número inteiro: "))
n2 = int(input("Digite o 2º número inteiro: "))
n3 = int(input("Digite o 3º número inteiro: "))

menor = min(n1, n2, n3)
maior = max(n1, n2, n3)
meio = (n1 + n2 + n3) - maior - menor
print("O menor valor é: ", menor)
print("O valor do meio é: ", meio)
print("O maior valor é: ", maior)