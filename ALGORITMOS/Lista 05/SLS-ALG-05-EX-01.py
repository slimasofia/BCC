# Teorema de pitágoras: a² = b² + c²
import math

def calcular_hipotenusa(lado1, lado2):
    hipotenusa = math.sqrt((lado1**2) + (lado2**2))
    return hipotenusa

def main():
    lado1 = float(input("Digite o comprimento do primeiro lado: "))
    lado2 = float(input("Digite o comprimento do segundo lado: "))
    
    hipotenusa = calcular_hipotenusa(lado1, lado2)
    print("A hipotenusa é: ", hipotenusa)


main()
