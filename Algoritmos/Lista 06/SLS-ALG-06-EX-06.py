divisores = []
def calcular_divisores(n):
    for i in range(1, n):
        if n % i == 0:
            divisores.append(i)
    return divisores

def main():
    n = int(input("Digite um inteiro: "))
    lista_divisores = calcular_divisores(n)
    print(f"Divisores de {n}: {lista_divisores}")

main()
