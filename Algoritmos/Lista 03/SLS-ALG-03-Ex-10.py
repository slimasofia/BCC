letra = input("Defina a letra da casa: ")
numero = int(input("Defina o número da casa: "))

if(letra == "a" or letra == "c" or letra == "e" or letra == "g"):
    coluna = "preto"
else:
    coluna =  "branco"

if(numero % 2 == 0):
    linha = "branco"
else:
    linha = "preto"

if(coluna == linha):
      print("quadrado preto")
else:
    print("Quadrado branco")