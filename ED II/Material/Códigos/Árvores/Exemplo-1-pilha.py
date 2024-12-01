stack = []

# Usando a função append (funciona como push)
stack.append('a')
stack.append('b')
stack.append('c')

print('Estado inicial da pilha:')
print(stack)

# Semelhante à função size()
print('Tamanho da pilha:')
print(len(stack))

# Remoção de dois elementos da pilha
stack.pop()
stack.pop()

print('Estado final da pilha:')
print(stack)

# Semelhante à função size()
print('Tamanho da pilha:')
print(len(stack))

# Implemente top() e empty()!