import math

a = float(input("Dgite o valor de a: "))
b = float(input("Dgite o valor de b: "))
c = float(input("Dgite o valor de c: "))

discriminante = (b**2 - 4*a*c)

if(discriminante < 0):
    print("A função não tem raízes. ")

elif(discriminante == 0):
    raiz = -b  / 2 * a
    print("A função tem uma raiz: ", raiz)

else:
    raiz_1 = (-b + math.sqrt(discriminante)) / 2 * a
    raiz_2 = (-b - math.sqrt(discriminante)) / 2 * a
    print(f"A função tem duas raízes. São elas: {raiz_1} e {raiz_2}")