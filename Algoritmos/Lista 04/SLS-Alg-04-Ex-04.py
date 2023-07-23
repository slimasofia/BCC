import math

x_1 = float(input("Digite a coordenada x de um ponto: "))
y_1 = float(input("Digite a coordenada y de um ponto: "))
perimetro = 0
x_ant = x_1
y_ant = y_1

while True:
    resposta = input("Digite a coordenada x de um ponto: ")
    if resposta == "":
        break
    x_atual = float(resposta)
    y_atual = float(input("Digite a coordenada y de um ponto: "))
    distancia = math.sqrt((y_atual - y_ant)**2 + (x_atual-x_ant)**2)
    perimetro = perimetro + distancia
    
    x_ant = x_atual
    y_ant = y_atual

distancia = math.sqrt((y_1 - y_ant)**2 + (x_1-x_ant)**2)
perimetro = perimetro + distancia
print(perimetro)

    