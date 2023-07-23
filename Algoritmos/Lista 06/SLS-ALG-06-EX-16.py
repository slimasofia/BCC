#(exercício 15)
simbolos = ['+', '-', '*', '/', '(', ')' '[', '{']
op = simbolos[0:4]

def tokenizar(expressao):
    tokens = []
    numero_atual = ''
    
    for caractere in expressao:
        if caractere.isdigit():
            numero_atual += caractere
        elif caractere == '+' or caractere == '-':
            if numero_atual:
                tokens.append(numero_atual)
                numero_atual = ''
            if not tokens or tokens[-1] in simbolos:
                numero_atual += caractere
            else:
                tokens.append(caractere)
        elif caractere.isspace():
            if numero_atual:
                tokens.append(numero_atual)
                numero_atual = ''
        else:
            if numero_atual:
                tokens.append(numero_atual)
                numero_atual = ''
            tokens.append(caractere)
    
    if numero_atual:
        tokens.append(numero_atual)
    return tokens

#(exercício 14)
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


expressao = input('Digite a expressão matemática: ')
tokens_infix = tokenizar(expressao)

# exercício 16 começa aqui
operadores = []
postfix = []
def posfixa(tokens_infix):
    for token in tokens_infix:
        if token not in simbolos:  # se token for um inteiro
            postfix.append(token)
        if token in op:  # se token for um operador
            while operadores and operadores[-1] != "(" and precedencia(token) <= precedencia(operadores[-1]):
                postfix.append(operadores.pop())
            operadores.append(token)
        if token == "(":
            operadores.append(token)
        if token == ")": 
            while operadores and operadores[-1] != "(":
                postfix.append(operadores.pop())
            if operadores and operadores[-1] == "(":
                operadores.pop()

    while operadores:
        postfix.append(operadores.pop())

    return postfix

tokens_infix = tokenizar(expressao)
print("Forma infixa: ",tokens_infix)
postfix = posfixa(tokens_infix)
print("Posfixa: ",postfix)