import math

t1 = float(input("Qual é a latitude do ponto um? "))
g1 = float(input("Qual é a longitude do ponto um? "))

t2 = float(input("Qual é a latitude do ponto dois? "))
g2 = float(input("Qual é a longitude do ponto dois? "))


t1_r = (t1 * math.pi)/180
g1_r = (g1 * math.pi)/180
t2_r = (t2 * math.pi)/180
g2_r = (g2 * math.pi)/180


distancia = 6371.01 * math.acos(math.sin(t1_r) * math.sin(t2_r) + math.cos(t1_r) * math.cos(t2_r) * math.cos(g1_r - g2_r))
print("A distância é: {:.2f}".format(distancia),"quilômetros")