# Função para adicionar um elemento à pilha (push)
def push(stack, element):
    stack.append(element)

# Função para remover e retornar o elemento do topo da pilha (pop)
def pop(stack):
    if not empty(stack):
        return stack.pop()
    else:
        return "Pilha vazia"

# Função para obter o tamanho da pilha
def size(stack):
    return len(stack)

# Função para verificar se a pilha está vazia
def empty(stack):
    return len(stack) == 0

# Função para obter o elemento do topo da pilha
def top(stack):
    if not empty(stack):
        return stack[-1]
    else:
        return None

# Criando a pilha
stack = []

# Usando a função push para adicionar elementos
push(stack, 'a')
push(stack, 'b')
push(stack, 'c')

print('Estado inicial da pilha:')
print(stack)

# Usando a função size()
print('Tamanho da pilha:')
print(size(stack))

# Usando a função top() para obter o elemento do topo da pilha
print('O elemento no topo da pilha é:')
print(top(stack))

# Usando a função empty() para verificar se a pilha está vazia
print('Pilha vazia?')
print(empty(stack))

# Remoção de dois elementos da pilha
pop(stack)
pop(stack)

print('Estado final da pilha:')
print(stack)

# Usando a função size()
print('Tamanho da pilha:')
print(size(stack))

# Usando a função top() para obter o elemento do topo da pilha
print('O elemento no topo da pilha é:')
print(top(stack))

# Usando a função empty() para verificar se a pilha está vazia
print('Pilha vazia?')
print(empty(stack))

# Remove o último elemento da pilha
pop(stack)

# Usando a função empty() para verificar se a pilha está vazia
print('Pilha vazia?')
print(empty(stack))