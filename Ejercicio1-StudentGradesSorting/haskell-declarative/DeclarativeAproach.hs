-- Lista de estudiantes
students :: [(String, Int)]
students =
  [ ("Alice", 88)
  , ("Bob", 95)
  , ("Charlie", 88)
  , ("Diana", 92)
  , ("Eve", 95)
  ]

-- Funcion sorteadora recursiva
sortStudents :: [(String, Int)] -> [(String, Int)]
sortStudents [] = []
sortStudents (x:xs) =
  let smallerOrEqual = [y | y <- xs, (snd y, fst y) <= (snd x, fst x)]
      bigger = [y | y <- xs, (snd y, fst y) > (snd x, fst x)]
  in sortStudents bigger ++ [x] ++ sortStudents smallerOrEqual

-- Imprimir lista sorteada
main :: IO ()
main = mapM_ (\(name, grade) -> putStrLn $ name ++ ": " ++ show grade) (sortStudents students)
