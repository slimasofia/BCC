def verificar_ordem(lista):
    lista_ordenada = sorted(lista)
    if lista == lista_ordenada:
        return True
    else:
        return False

lista = []

while True:
    itens = input("Digite os itens da lista (ou enter para sair): ")
    if itens == "":
        break
    else:
        lista.append(itens)

def main():
    if verificar_ordem(lista):
        print("A lista já está classificada corretamente. ")
    else:
        print("A lista ainda não está classificada. ")

main()