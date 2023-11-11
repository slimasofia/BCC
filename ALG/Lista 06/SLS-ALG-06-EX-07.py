def verificar_numero(n):
    divisores = []
    for i in range(1, n):
        if n % i == 0:
            divisores.append(i)

    soma = sum(divisores)
    if soma == n:
        return True
    else:
        return False

def main():
    for n in range(1, 10000):
        if verificar_numero(n):
            print(f"{n} é um número perfeito. ")
  
main()