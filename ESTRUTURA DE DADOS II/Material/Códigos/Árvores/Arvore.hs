data Arvore a = ArvoreVazia 
              | No a (Arvore a) (Arvore a)
              deriving (Show, Eq)

inserir :: (Ord a) => a -> Arvore a -> Arvore a
inserir x ArvoreVazia = No x ArvoreVazia ArvoreVazia
inserir x (No a esquerda direita)
    | x == a = No x esquerda direita
    | x < a  = No a (inserir x esquerda) direita
    | x > a  = No a esquerda (inserir x direita)

buscar :: (Ord a) => a -> Arvore a -> Bool
buscar x ArvoreVazia = False
buscar x (No a esquerda direita)
    | x == a = True
    | x < a  = buscar x esquerda
    | x > a  = buscar x direita

preOrdem :: Arvore a -> [a]
preOrdem ArvoreVazia = []
preOrdem (No a esquerda direita) = [a] ++ preOrdem esquerda ++ preOrdem direita

emOrdem :: Arvore a -> [a]
emOrdem ArvoreVazia = []
emOrdem (No a esquerda direita) = emOrdem esquerda ++ [a] ++ emOrdem direita

posOrdem :: Arvore a -> [a]
posOrdem ArvoreVazia = []
posOrdem (No a esquerda direita) = posOrdem esquerda ++ posOrdem direita ++ [a]

main :: IO ()
main = do
    let arvore = foldr inserir ArvoreVazia [8,3,10,1,6,14,4,7,13]
    print arvore
    
    putStrLn "Pré-ordem:"
    print $ preOrdem arvore
    
    putStrLn "Em ordem:"
    print $ emOrdem arvore
    
    putStrLn "Pós-ordem:"
    print $ posOrdem arvore

    putStrLn "Buscando o valor 6 na árvore:"
    print $ buscar 6 arvore
    
    putStrLn "Buscando o valor 15 na árvore:"
    print $ buscar 15 arvore

    -- Inserindo mais dados na árvore
    let arvoreAtualizada = foldr inserir arvore [11, 68, 15, 78, 13]

    putStrLn "Buscando o valor 15 na árvore:"
    print $ buscar 15 arvoreAtualizada