total = 0
while True:
    i = input("Digite uma idade: (ou espaço em branco pra finalizar) ")
    if i == "":
        break
    idade = int(i)
    if idade <= 2:
        total += 0
    elif idade >= 3 and idade <= 12:
        total += 14
    elif idade >= 65:
        total += 18
    else:
        total+= 23

print("O valor total é de: R${:.2f}".format(total))


