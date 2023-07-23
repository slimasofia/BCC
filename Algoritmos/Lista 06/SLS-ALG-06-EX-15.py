simbolos = ['+', '-', '*', '/', '(', '[', '{']

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

expressao = input('Digite a expressão matemática: ')
tokens = tokenizar(expressao)
print(tokens)