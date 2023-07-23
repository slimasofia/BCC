# de qualquer base pra base 10 somatório de potencias
# e da 10 pra qualquer outra

# def n2dez(num, base_num): 

# return num_convertido


# binário para decimal, octal para decimal, hexadecimal para decimal

# se o usuário quiser converter qualquer coisa para decimal
num = input("Digite o número a ser convertido: ")
base_num = input("Digite em qual base o número está: ")
bqmq = input("Para qual base você quer converter? (0 a 16): ")


p = 0

if bqmq == '10':
    if base_num == '2':
        print(num)
        resultado = num[-1] * (2**p)

    
    
    # o número da última posição * 2 
    # elevado a posição que o número ta (de tras pra frente)


#octal

#binario

#hexadecimal

#decimal

# num = input("Digite o número binário a ser convertido: ")
# resultado = 0

# for i in range(len(num)):
#     digito = int(num[-(i+1)])
#     resultado += digito * (2**i)

# print("O número decimal equivalente é:", resultado)
