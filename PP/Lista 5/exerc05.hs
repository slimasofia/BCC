{-

Interprete o comando abaixo:
    *Main> :t decremento (incremento 9)
    decremento(incremento 9) :: Num a => a

":t" é usado para retornar o tipo da função. Nesse caso, a classe de tipo da 
função foi inferida já que nenhum tipo foi explicitamente informado.
poderíamos definir os tipos:

incremento:: Double -> Double
decremento:: Double -> Double

e será retornado:
decremento(incremento 9) :: Double

-}
