d = int(input("Digite os dias: ")) * 86400
h = int(input("Digite as horas: ")) * 3600
m = int(input("Digite os minutos: ")) * 60
s = int(input("Digite os segundos: "))


total_segundos = d + h + m + s
print(f"O intervalo de tempo informado corresponde a {total_segundos} segundos.")


