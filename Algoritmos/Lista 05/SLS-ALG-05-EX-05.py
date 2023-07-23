def retorna_ordinal(inteiro):
    if inteiro == 1:
        return "Primeiro"
    elif inteiro == 2:
        return "Segundo"
    elif inteiro == 3:
        return "Terceiro"
    elif inteiro == 4:
        return "Quarto"
    elif inteiro == 5:
        return "Quinto"
    elif inteiro == 6:
        return "Sexto"
    elif inteiro == 7:
        return "Sétimo"
    elif inteiro == 8:
        return "Oitavo"
    elif inteiro == 9:
        return "Nono"
    elif inteiro == 10:
        return "Décimo"
    elif inteiro == 11:
        return "Décimo primeiro"
    elif inteiro == 12:
        return "Décimo segundo"
    else:
        return ""

for inteiro in range(1, 13):
    ordinal = retorna_ordinal(inteiro)
    print(f"{inteiro} = {ordinal}") 

