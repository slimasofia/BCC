def determinar_data(dia, mes, ano):
    ultimos_digitos_ano = int(str(ano)[2::])
    if dia * mes == ultimos_digitos_ano:
        return True  #data mágica
    else:
        return False

for ano in range(1901, 2001):
    for mes in range(1, 13):
        for dia in range(1, 32):
            if determinar_data(dia, mes, ano):
                print(f"{dia}/{mes}/{ano} é uma data mágica.")