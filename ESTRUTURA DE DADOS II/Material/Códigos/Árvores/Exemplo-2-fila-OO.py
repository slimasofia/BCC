class Queue:
    def __init__(self):
        self.queue = []

    def empty(self):
        return len(self.queue) == 0

    def size(self):
        return len(self.queue)

    def enqueue(self, element):
        self.queue.append(element)

    def dequeue(self):
        if not self.empty():
            return self.queue.pop(0)
        else:
            return "Fila vazia"

    def front(self):
        if not self.empty():
            return self.queue[0]
        else:
            return None

q = Queue()
q.enqueue('a')
q.enqueue('b')
q.enqueue('c')

print('Estado inicial da fila:')
print(q.queue)

print('Tamanho da fila:')
print(q.size())

print('Elemento no início da fila:')
print(q.front())

q.dequeue()
q.dequeue()

print('Estado da fila após duas remoções:')
print(q.queue)

print('Tamanho da fila:')
print(q.size())

print('Elemento no início da fila:')
print(q.front())

print('Fila está vazia?')
print(q.empty())

# Remoção do último elemento da fila
q.dequeue()

print('Fila está vazia?')
print(q.empty())