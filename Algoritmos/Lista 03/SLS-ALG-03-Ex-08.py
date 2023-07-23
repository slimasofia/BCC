nota = (input("Digite a nota musical desejada: "))
oitavas = int(input("Digite a oitava desejada: "))

if nota == "C" or nota == "c":
    frequencia = 261.63/(2**(4-oitavas))
    print("A frequencia é: " , frequencia)

elif nota == "D" or nota == "d":
    frequencia = 293.66/(2**(4-oitavas))
    print("A frequencia é: " , frequencia)

elif nota == "E" or nota == "e":
    frequencia = 329.63/(2**(4-oitavas))
    print("A frequencia é: " , frequencia)

elif nota == "F" or nota == "f":
    frequencia = 349.23/(2**(4-oitavas))
    print("A frequencia é: " , frequencia)

elif nota == "G" or nota == "g":
    frequencia = 392.00/(2**(4-oitavas))
    print("A frequencia é: " , frequencia)

elif nota == "A" or nota == "a":
    frequencia = 440.00/(2**(4-oitavas))
    print("A frequencia é: " , frequencia)

elif nota == "B" or nota == "b":
    frequencia = 493.88/(2**(4-oitavas))
    print("A frequencia é: " , frequencia)