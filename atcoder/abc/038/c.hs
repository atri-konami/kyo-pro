main = do
  n <- getLine
  as <- getLine
  let an = map read (words as) :: [Int]
  putStrLn . show $ solve an

solve (x:lis) = rec 1 1 x lis

rec n _ _ [] = n
rec n c r (x:lis) | r < x = n `seq` rec (n + c + 1) (c + 1) x lis
                  | otherwise = n `seq` rec (n + 1) 1 x lis
