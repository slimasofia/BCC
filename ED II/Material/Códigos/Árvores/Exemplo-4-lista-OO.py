class List:
    def __init__(self):
        self.list = []

    def empty(self):
        return len(self.list) == 0

    def size(self):
        return len(self.list)

    def get(self, indice):
        if 0 <= indice < len(self.list):
            return self.list[indice]
        else:
            return "Índice fora do intervalo"

    def insert(self, indice, elemento):
        if 0 <= indice <= len(self.list):
            self.list.insert(indice, elemento)
        else:
            return "Índice fora do intervalo"

    def remove(self, indice):
        if 0 <= indice < len(self.list):
            self.list.pop(indice)
        else:
            return "Índice fora do intervalo"

l = List()
l.insert(0, 'a')
l.insert(1, 'b')
l.insert(2, 'c')

print('Estado inicial da lista:')
print(l.list)

print('Tamanho da lista:')
print(l.size())

print('elementoo no índice 1:')
print(l.get(1))

l.remove(1)

print('Estado da lista após remoção:')
print(l.list)

print('Tamanho da lista:')
print(l.size())

print('Lista está vazia?')
print(l.empty())