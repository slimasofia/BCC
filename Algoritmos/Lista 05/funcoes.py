def funcao():
    print("Bloco de código")

funcao()


# A função recebe uma variável como parâmetro e imprime o que estiver armazenado nela
# A função é chamada e como parâmetro agora recebe o que eu desejo armazenar na variável

def print_name(name):
    print(f"Nome: {name}")

print_name("Sofia")

# Valores Default
# as variáveis flor e cor recebem, respectivamente, "Rosa" e "Vermelha" (esses são os valores padrão)
# Ao chamar a função, ela retorna o valor padrão ou o parâmetro que for passado

def flor(flor='Rosa', cor='Vermelha'):
    print("A cor da {flor} é {cor}")

flor()
flor("Orquídea", "Azul")

# Parâmetros *args
def maior_30(*args):
    print(args)
    print(type(args))

    for num in args:
        if num > 30:
            print(num)


maior_30(10, 20, 30, 40, 50, 60)

# exemplos
def soma_dois_numeros(valor1, valor2):
    soma = valor1 + valor2
    return soma


valor_soma = soma_dois_numeros(32, 15)
print(valor_soma)
print(soma_dois_numeros(50, 10))




# uma função que recebe o lado1 e lado2, mas seus valores não estão definidos. 
# a e b vão receber o que o usuário digitar (input) e esses valores aogra são os "novos" parâmetros da função

import math
def main(lado1, lado2):
    hipotenusa = math.sqrt((lado1**2) + (lado2**2))
    print("A hipotenusa é: ", hipotenusa)

a = int(input("Digite o comprimento do primeiro lado: "))
b = int(input("Digite o comprimento do segundo lado: "))
main(a, b)




# ex 6, 8, 16
