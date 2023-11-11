
print("       1   2   3   4   5   6   7   8   9  10 ")
" " 
 

# Imprimir tabela de multiplicação
for i in range(1, 11):
    print(f"{i:2} |", end="")
    for j in range(1, 11):
        produto = i * j
        print(f"{produto:4}", end="")
    print()