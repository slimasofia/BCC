bits = input("Digite a sequência de bits: ")
total = 0

for x in bits:
    if (bits == "1"):
        total = total + 1
if total % 2 == 0:
    print("O bit de verificação é 1 ")
else:
    print("O bit de verificação é 0")

    
