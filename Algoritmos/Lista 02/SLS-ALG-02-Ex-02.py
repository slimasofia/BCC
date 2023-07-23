n_segundos = int(input("Digite uma quantidade de tempo em segundos: "))
d = n_segundos // 86400
h = (n_segundos % 86400) // 3600
m = (n_segundos % 3600) // 60
s = n_segundos % 60

print(f"No formato D:HH:MM:SS o intervalo de tempo digitado corresponde {d}:{h:02}:{m:02}:{s:02}")

