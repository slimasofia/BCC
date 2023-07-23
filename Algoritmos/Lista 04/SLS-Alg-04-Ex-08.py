x = input("Digite a mensagem: ")
mensagem = x.lower()
deslocamento = int(input("Digite a distância de deslocamento de letras: "))

for letra in mensagem:
    x = ord(letra)
    print(chr(x + deslocamento))