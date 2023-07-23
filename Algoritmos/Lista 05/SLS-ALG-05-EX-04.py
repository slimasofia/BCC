def calcular_mediana(n1, n2, n3):
    menor = min(n1, n2, n3)
    maior = max(n1, n2, n3)
    meio = (n1 + n2 + n3) - maior - menor
    return meio

n1 = int(input("Digite o 1º número: "))
n2 = int(input("Digite o 2º número: "))
n3 = int(input("Digite o 3º número: "))

meio = calcular_mediana(n1, n2, n3)
print("A medianna é: ", meio)



