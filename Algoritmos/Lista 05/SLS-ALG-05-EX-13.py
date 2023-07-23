def determinar_dias(mes, ano):
    if mes == 4 or mes == 6 or mes == 9 or mes == 11: 
        dias = 30
    elif mes == 2:
        if ano % 4 != 0: 
            dias = 28
        else:
            dias = 29
   
    else:
      dias = 31

    return dias

mes = int(input("Digite o mês do ano (de 1 a 12): "))    
ano = int(input("Digite o ano: ")) 

numero_dias = determinar_dias(mes, ano)
print(f"O mês {mes} tem {numero_dias} dias.")