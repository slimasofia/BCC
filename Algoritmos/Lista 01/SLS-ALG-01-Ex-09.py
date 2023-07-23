v_inicial = float(input("Qual é o valor inicial depositado na conta? "))
v_um = (v_inicial / 100) * 12 + v_inicial
v_dois = (v_um / 100) * 12 + v_um
v_tres = (v_dois / 100) * 12 + v_dois

print("O seu saldo no primeiro ano é: R$ {:.2f}".format(v_um))
print("O seu saldo no segundo ano é: R$ {:.2f}".format(v_dois))
print("O seu saldo no terceiro ano é: R$ {:.2f}".format(v_tres))