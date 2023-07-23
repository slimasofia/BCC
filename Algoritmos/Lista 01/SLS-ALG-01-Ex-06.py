v_suco = float(input("Qual é o valor do suco? "))
v_prato = float(input("Qual é o valor do prato principal? "))
v_sobremesa = float(input("Qual é o valor da sobremesa? "))


v_conta = (v_suco + v_prato + v_sobremesa) 
v_final = (v_conta / 100) * 10 + v_conta
print("O total da sua conta é: R$ {:.2f}".format(v_final))
