def validar_triangulo(c1, c2, c3):
    maior =  max(c1, c2, c3)
    menor = min(c1, c2, c3)
    meio = (c1 + c2 + c3) - maior - menor

    if maior >= menor + meio:
        return False
    else:
        return True

c1 = float(input("Digite o comprimento do primeiro canudo: "))
c2 = float(input("Digite o comprimento do segundo canudo: "))
c3 = float(input("Digite o comprimento do terceiro canudo: "))

if validar_triangulo(c1, c2, c3):
    print("É possível formar um triângulo.")
else:
    print("Não é possível formar um triângulo.")