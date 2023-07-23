def precedencia(operador):
    if operador == "+" or operador == "-":
        return 1
    elif operador == "*" or operador == "/":
        return 2
    elif operador == "^":
        return 3
    else:
        print("Erro: a entrada não é um operador ")
        return -1
    
def main():
    operador = input("Digite um operador: ")
    p = precedencia(operador)
    print(p)
    
main()    