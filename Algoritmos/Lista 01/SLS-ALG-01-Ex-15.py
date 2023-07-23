import math

l = float(input("Digite o comprimento do lado: "))
n = int(input("Digite o número de lados: "))

area = (n * (l ** 2)) / (4 * math.tan(math.pi / n))

print("A área é: ", area)