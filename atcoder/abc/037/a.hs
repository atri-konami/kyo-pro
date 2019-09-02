main = do
  a <- getLine
  let abc = map read $ words a :: [Int]
  print $ solve abc

solve l = max (c `div` a) (c `div` b)
  where a = l !! 0
        b = l !! 1
        c = l !! 2
