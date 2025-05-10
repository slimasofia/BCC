{-

Qual é o resultado da expressão abaixo? Por quê?
(1 == 4 && True, mod (4*8) 31^2-5)

O resultado será (False, -4).

-A expressão do lado esquerdo é avaliada na seguinte ordem:

1 == 4 --> False
    False && True --> False


-A expressão do lado direito é avaliada na ordem:
(4*8) --> 32
    mod 32 31 --> 1
        1^2-5 --> -4 

Logo, o resultado é (False, -4)

-}    

