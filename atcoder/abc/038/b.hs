parsehw :: String ->  [Int]
parsehw s = map read (words s) :: [Int]

solve :: [Int] -> [Int] -> String
solve l1 l2 = if length [(x, y) | x <- l1, y <- l2, x == y] > 0 then "YES" else "NO"

main = do
  s1 <- getLine
  s2 <- getLine
  let hw1 = parsehw s1
  let hw2 = parsehw s2
  putStrLn $ solve hw1 hw2

