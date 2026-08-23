import numpy as np

# NÃO-BÁSICAS: x1, x2 (variáveis originalmente do problema)
# BÁSICAS: x3, x4, x5 (variáveis de folga adicionadas para transformar as desigualdades em igualdades)

# max 3x1 + 5x2
# s.a.
# x1 <= 4
# 2x2 <= 12
# 3x1 + 2x2 <= 18

def simplex(A, b, c):
    A = np.array(A, dtype=float)
    b = np.array(b, dtype=float)
    c = np.array(c, dtype=float)

    # número de variáveis 
    n = A.shape[1] # numero de colunas da matriz A

    # número de restrições
    m = A.shape[0] # número de linhas da matriz A

    simplex_table = np.zeros((m + 1, n + m + 1)) # cria uma tabela simplex com zeros

    # (o np.hstack empilha os arrays horizontalmente)
    # o :-1 significa que estamos pegando todas as linhas e todas as colunas, exceto a última coluna
    simplex_table[:-1, :-1] = np.hstack((A, np.eye(m))) # adiciona a matriz A e a matriz identidade na tabela
    simplex_table[:-1, -1] = b # adiciona o vetor b na última coluna da tabela 
    simplex_table[-1, :-1] = np.hstack((-c, np.zeros(m))) # adiciona os coeficientes da função objetivo na última linha da tabela

    basic_vars = list(range(n, n + m))  # variáveis básicas (x3, x4, x5)
    non_basic_vars = list(range(n))     # variáveis não-básicas (x1, x2)

    while True:

        # teste de otimalidade: se todos os coeficientes da função objetivo forem menores ou iguais a zero, a solução é ótima 
        linha_objetivo = simplex_table[-1, :-1]
        if np.all(linha_objetivo >= -1e-9): # tolerância para evitar problemas de arredondamento
            print("Solução ótima encontrada.")
            return simplex_table, basic_vars, non_basic_vars  

        # calcular a próxima variável a entrar na base (se tornará básica)
        entering_var_index = np.argmin(linha_objetivo) # índice da variável que entrará na base 

        # calcular a variável a sair da base (se tornará não-básica)
        # percorrer as linhas da tabela para calcular a razão (razão mínima)
        razao_minima = np.inf
        leaving_var_index = -1
        for i in range(m):
            # utilizamos o "i" para percorrer as linhas da tabela simplex, que correspondem às restrições do problema.
            # e utilizamos o "entering_var_index" para acessar a coluna correspondente à variável que entrará na base.
            if simplex_table[i, entering_var_index] > 0: # apenas considerar linhas com coeficiente positivo
                # calcula a razão:
                razao = simplex_table[i, -1] / simplex_table[i, entering_var_index]
                if razao < razao_minima: # atualizar a razão mínima e o índice da variável a sair da base
                    razao_minima = razao
                    leaving_var_index = i

        # aplicar gauss-jordan com a linha pivot (linha da variável que sairá da base) 
        # e a coluna pivot (coluna da variável que entrará na base)
        # o objetivo de aplicar gauss-jordan é transformar a coluna pivot em uma coluna unitária, 
        # ou seja, com 1 na linha pivot e 0 nas demais linhas, para que assim possamos atualizar a base e a solução do problema.

        pivot = simplex_table[leaving_var_index, entering_var_index]    # elemento pivot
        # essa operação significa que estamos dividindo todos os 
        # elementos da linha pivot pelo valor do elemento pivot, para que o elemento pivot se torne 1. (normalizar)
        simplex_table[leaving_var_index, :] /= pivot 
        # agora, para cada linha da tabela, exceto a linha pivot, subtraímos 
        # a linha pivot multiplicada pelo coeficiente da coluna pivot na linha atual.
        for i in range(m + 1):
            if i != leaving_var_index:
                simplex_table[i, :] -= simplex_table[leaving_var_index, :] * simplex_table[i, entering_var_index]

            
        # atualizar as variáveis básicas e não-básicas
        leaving_var = basic_vars[leaving_var_index]

        basic_vars[leaving_var_index] = entering_var_index

        non_basic_vars.remove(entering_var_index)
        non_basic_vars.append(leaving_var)


        print("Tabela Simplex:")
        print(simplex_table)

        print("\nVariáveis básicas:", basic_vars)
        print("Variáveis não-básicas:", non_basic_vars)

        print(f"Variável a entrar na base: x{entering_var_index + 1}")
        print(f"Variável a sair da base: x{leaving_var + 1}")
    
    return simplex_table, basic_vars, non_basic_vars

if __name__ == "__main__": 
    A = np.array([[1, 0], [0, 2], [3, 2]])
    b = np.array([4, 12, 18])
    c = np.array([3, 5])


    simplex(A, b, c)
