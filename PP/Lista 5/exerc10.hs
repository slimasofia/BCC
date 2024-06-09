{-

Prelude> negate -8
<interactive>:3:1:

Non type-variable argument in the constraint: Num (a -> a)
(Use FlexibleContexts to permit this)
When checking that ‘it’ has the inferred type
it :: forall a. (Num a, Num (a -> a)) => a -> a

O erro é devido ao argumento "-8" que não está sendo entendido como um número. 
Para corrigir é necessário colocá-lo entre parênteses:

ghci> negate (-8)
8

-}