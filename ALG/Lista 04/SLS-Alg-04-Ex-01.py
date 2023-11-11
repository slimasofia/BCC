# Média aritmética. Escreva um programa Python que calcula a média aritmética de um
# conjunto de valores fornecidos pelo usuário. O usuário deve entrar com o valor 0 indicando
# que não serão mais fornecidos novos valores. Seu programa deve exibir uma mensagem de
# erro se o primeiro valor fornecido pelo usuário for 0.



soma = 0
div = 0
numero = float(input("Digite um valor (0 para sair): "))


if numero == 0:
    print("O primeiro número não pode ser zero.")
else:
    while numero != 0:
        soma += numero
        
        div += 1
        numero = float(input("Digite outro valor (0 para sair): "))

    media = soma / div
    print("A média aritmética dos números digitados é:", media)