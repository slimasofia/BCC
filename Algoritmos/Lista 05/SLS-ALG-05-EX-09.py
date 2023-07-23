def isInteger(inteiro):
    inteiro = inteiro.strip()

    if len(inteiro) >= 1 and inteiro.isdigit():
        return True

    elif len(inteiro) >= 2 and (inteiro[0] == '-' or inteiro[0] == '+') and inteiro[1:].isdigit():
        return True

    else:
        return False

inteiro = input("Digite um número: ")
if isInteger(inteiro):
    print("A string representa um número inteiro.")
else:
    print("A string não representa um número inteiro.")
