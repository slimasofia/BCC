n = []
p = []
z = []
while True:
    i = input("Digite um inteiro: ")
    if i == "":
        break
    else:
        if i == "0":
            z.append(i)
        elif "-" in i:
            n.append(i)   
        else:   
            p.append(i)

inteiros = []
inteiros = n + z + p 
for i in inteiros:
    print(i)

