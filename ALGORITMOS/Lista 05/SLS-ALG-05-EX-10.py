def verifica_numero(numero):
 if numero <= 1 or numero % 2 != 0:
  return True
 else:
  return False

  
numero = int(input("Digite um número para verificar se ele é primo: "))
if verifica_numero(numero):
 print("é um número primo. ")
else:
 print("Não é um número primo. ")



