# mesas - x
# cadeiras - y
# Função objetivo:  50x + 30y
#                   3x + 2y 
#                   x + 2y < 200
#                   y < 80 < 300
#                   x, y >= 0

from pulp import *

# Modelo
model = LpProblem("Exemplo", LpMaximize)

# Variáveis
# x = mesas
# y = cadeiras
x = LpVariable("x", lowBound=0)
y = LpVariable("y", lowBound=0, upBound=80)

# Objetivo
model += 50*x + 30*y

# Restrição
model += 3*x + 2*y <= 300
model += x + 2*y <= 200

# Resolver
model.solve(PULP_CBC_CMD(msg=False))

print("Status:", LpStatus[model.status])
print("Função Objetivo:", value(model.objective))
print("x =", value(x))
print("y =", value(y))
