import qualified Data.Set as Set

type Grafo = [(Int, [Int])]

dfsCiclo :: Grafo -> Set.Set Int -> Int -> Int -> Bool
dfsCiclo grafo visitado vertice pai = 
    let visitado' = Set.insert vertice visitado
        vizinhos = case lookup vertice grafo of
            Just vs -> vs
            Nothing -> []
    in any (\v -> if not (Set.member v visitado')
                    then dfsCiclo grafo visitado' v vertice
                    else v /= pai) vizinhos

temCiclo :: Grafo -> Bool
temCiclo [] = False
temCiclo ((v, vizinhos):grafo) = dfsCiclo ((v, vizinhos):grafo) Set.empty v (-1)

main :: IO ()
main = do
    let grafo = [(0, [1]), (1, [0, 2]), (2, [1, 3]), (3, [2, 4]), (4, [3, 0])]
    
    if temCiclo grafo
        then putStrLn "O grafo tem um ciclo."
        else putStrLn "O grafo não tem ciclos."
