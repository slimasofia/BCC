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

# Obtém o elemento do topo da pilha
print('O elemento no topo da pilha é:')
print(stack[-1])

# Verifica se a pilha está vazia
print('Pilha vazia?')
print(len(stack) == 0)

# Remoção de dois elementos da pilha
stack.pop()
stack.pop()

print('Estado final da pilha:')
print(stack)

# Semelhante à função size()
print('Tamanho da pilha:')
print(len(stack))

# Obtém o elemento do topo da pilha
print('O elemento no topo da pilha é:')
print(stack[-1])

# Verifica se a pilha está vazia
print('Pilha vazia?')
print(len(stack) == 0)

#Remove o elemento da pilha
stack.pop()

# Verifica se a pilha está vazia
print('Pilha vazia?')
print(len(stack) == 0)