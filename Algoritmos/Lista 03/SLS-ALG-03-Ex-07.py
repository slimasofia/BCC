decibeis = float(input("Digite um valor em decibéis: "))

if(decibeis == 130):
    print("O tipo de barulho equivale a: britadeira.")
elif(106 < decibeis < 130):
    print("O tipo de barulho está entre: cortador de grama e britadeira.")

elif(decibeis == 106):
    print("O tipo de barulho equivale a: cortador de grama.")

elif(70 < decibeis < 106):
    print("O tipo de barulho está entre: cortador de grama e britadeira.")

elif(decibeis == 70):
   print("O tipo de barulho equivale a: despertador. ")

elif(40 < decibeis < 70):
   print("O tipo de barulho está entre: despertador e sala silenciosa. ")

elif(decibeis == 40):
   print("O tipo de barulho é equivalente a: sala silenciosa")
else:
 print("O valor digitado não está relacionado na tabela.")