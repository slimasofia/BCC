v_menor = float(input("Quantos vasilhames de um litro ou menos você quer reciclar? "))
v_maior = float(input("E de mais de um litro? "))

cred_menor = v_menor * 10
cred_maior = v_maior * 25

cred_total = (cred_menor + cred_maior) / 100
print("O seu crédito é de: R$ {:.2f}".format(cred_total))

