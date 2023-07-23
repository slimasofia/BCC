lado_1 = float(input("Digite o comprimento do lado 1: "))
lado_2 = float(input("Digite o comprimento do lado 2: "))
lado_3 = float(input("Digite o comprimento do lado 3: "))

if( lado_1 == lado_2 == lado_3):
    print("Triângulo equilátero. ")
elif(lado_1 == lado_2 or lado_1 == lado_3 or lado_2 == lado_3):
    print("Triângulo isóceles. ")
else:
    print("Triãngulo escaleno. ")