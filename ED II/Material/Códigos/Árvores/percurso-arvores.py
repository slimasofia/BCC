class No:
    def __init__(self, val):
        self.val = val
        self.esq = None
        self.dir = None

def preOrdem(raiz):
    if raiz is not None:
        print(raiz.val, end=" ")
        preOrdem(raiz.esq)
        preOrdem(raiz.dir)

def emOrdem(raiz):
    if raiz is not None:
        emOrdem(raiz.esq)
        print(raiz.val, end=" ")
        emOrdem(raiz.dir)

def posOrdem(raiz):
    if raiz is not None:
        posOrdem(raiz.esq)
        posOrdem(raiz.dir)
        print(raiz.val, end=" ")

if __name__ == "__main__":

    raiz = No(1)
    raiz.esq = No(2)
    raiz.dir = No(3)
    raiz.esq.esq = No(4)
    raiz.esq.dir = No(5)

    print("Travessia Pré-Ordem: ", end="")
    preOrdem(raiz)
    print()

    print("Travessia Em-Ordem: ", end="")
    emOrdem(raiz)
    print()

    print("Travessia Pós-Ordem: ", end="")
    posOrdem(raiz)
    print()