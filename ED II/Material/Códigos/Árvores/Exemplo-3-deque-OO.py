class Deque:
    def __init__(self):
        self.deque = []

    def empty(self):
        return len(self.deque) == 0

    def size(self):
        return len(self.deque)

    def push_front(self, element):
        self.deque.insert(0, element)

    def push_back(self, element):
        self.deque.append(element)

    def pop_front(self):
        if not self.empty():
            return self.deque.pop(0)
        else:
            return "Deque vazia"

    def pop_back(self):
        if not self.empty():
            return self.deque.pop()
        else:
            return "Deque vazia"

    def front(self):
        if not self.empty():
            return self.deque[0]
        else:
            return None

    def back(self):
        if not self.empty():
            return self.deque[-1]
        else:
            return None

d = Deque()
d.push_back('a')
d.push_back('b')
d.push_front('c')

print('Estado inicial do deque:')
print(d.deque)

print('Tamanho do deque:')
print(d.size())

print('Elemento no início do deque:')
print(d.front())

print('Elemento no fim do deque:')
print(d.back())

d.pop_front()
d.pop_back()

print('Estado do deque após remoções:')
print(d.deque)

print('Tamanho do deque:')
print(d.size())

print('Deque está vazio?')
print(d.empty())