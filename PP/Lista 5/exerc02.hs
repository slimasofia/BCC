{-

Cite um valor matemático para o qual os operadores ** e ^ não apresentam o mesmo
comportamento.

Podemos citar as expressões 2^(-3) e 2**(-3) que se comportam de maneiras diferentes devido aos operadores:

ghci> 2 ** (-3)
0.125
ghci> 2^(-3)
*** Exception: Negative exponent

O erro ocorre pois o operador "^" aceita expoentes inteiros mas apenas não negativos.

-}