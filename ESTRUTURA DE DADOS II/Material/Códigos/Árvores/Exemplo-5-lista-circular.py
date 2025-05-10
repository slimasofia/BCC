class CircularList:
    def __init__(self):
        self.list = []
        self.size = 0

    def empty(self):
        return self.size == 0

    def length(self):
        return self.size

    def add(self, elemento):
        self.list.append(elemento)
        self.size += 1

    def remove(self, indice):
        if not self.empty() and 0 <= indice < self.size:
            self.list.pop(indice)
            self.size -= 1
        else:
            return "Índice fora do intervalo ou lista vazia"

    def get(self, indice):
        if not self.empty() and 0 <= indice < self.size:
            return self.list[indice]
        else:
            return "Índice fora do intervalo ou lista vazia"

    def display(self):
        if self.empty():
            return "Lista vazia"
        else:
            return self.list

cl = CircularList()

cl.add('a')
cl.add('b')
cl.add('c')
cl.add('d')

print('Estado inicial da lista circular:')
print(cl.display())

print('Tamanho da lista circular:')
print(cl.length())

print('elementoo no índice 2:')
print(cl.get(2))

cl.remove(1)

print('Estado da lista circular após remoção:')
print(cl.display())

print('Tamanho da lista circular:')
print(cl.length())

print('elementoo no índice 1 após remoção:')
print(cl.get(1))

print('Lista circular está vazia?')
print(cl.empty())