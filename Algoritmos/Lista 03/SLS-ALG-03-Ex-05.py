n_lados = int(input("Digite a quantidade de lados: "))

if (n_lados >= 3 and n_lados <= 10):
    if (n_lados == 3):
        print("Triângulo.")
    elif(n_lados == 4):
        print("Quadrilátero.") 
    elif(n_lados == 5):
        print("Pentágono.")
    elif(n_lados == 6):
        print("Hexágono.")
    elif(n_lados == 7):
        print("Heptágono.")
    elif(n_lados == 8):
        print("Octógono.")
    elif(n_lados == 9):
        print("Eneágono.")
    elif(n_lados == 10):
        print("Decágono.")

else:
    print("Digite um número válido. ")