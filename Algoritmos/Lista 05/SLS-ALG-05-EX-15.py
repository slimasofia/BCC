def hex2int(a):
    a = a.upper()
    hex = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
    return hex.index(a)

a = input("Digite um único dígito hexadecimal a ser convertido: ")
a_convertido = hex2int(a)
print(f"{a} em hexadecimal corresponde a: {a_convertido}" )

def int2hex(n):
    hex = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
    return hex.index[n]
    
n = int(input("Digite um decimal a ser convertido para hexadecimal: "))
n_convertido = hex2int(n)
print(f"{n} em hexadecimal corresponde a: {n_convertido}" )  