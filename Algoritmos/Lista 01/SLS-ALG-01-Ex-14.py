lado1 = int(input("Qual é o comprimento do primeiro lado? "))
lado2 = int(input("Qual é o comprimento do segundo lado? "))
lado3 = int(input("Qual é o comprimento do terceiro lado? "))

lado = (lado1 + lado2 + lado3) / 2
area = lado * (lado - lado1) * (lado - lado2) * (lado - lado3)**1/2
print(area)