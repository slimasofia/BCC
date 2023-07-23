data = input("Digite uma data no formato DDMMAA: ")

d = data[0:2]
m = data[2:4]
a = data[4:]
dataFormatada = a + m + d

print("A data no formato AAMMDD é: ", dataFormatada)