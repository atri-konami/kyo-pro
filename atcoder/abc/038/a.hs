solve :: String -> String
solve s = if ls == 'T' then "YES" else "NO"
  where ls = last s

main = do
  s <- getLine
  putStrLn $ solve s
