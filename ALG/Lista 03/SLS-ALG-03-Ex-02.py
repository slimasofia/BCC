idade = float(input("Digite a idade do cachorro em anos: "))
ano = float(5.25)

if idade <= 2 and idade == 1:
    print(ano * idade)
elif idade > 2:
    print("a idade é: ", (idade-2) * 4 + 2 * ano)
elif idade <= 0:
    print("Não use número negativo ou zero. ")
else:
    print("Digite um número intero. ")