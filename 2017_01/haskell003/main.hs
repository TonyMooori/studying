-- これ実装してく
-- http://vipprog.net/wiki/exercise.html

-- 素数判定

-- 約数を列挙する関数
factor :: Int -> [Int]
factor n = [ x | x <- [1..n+1], n `mod` x == 0]

-- 素数判定を行う関数
is_prime :: Int -> Bool
is_prime n = factor n == [1,n]

main = do
    n <- readLn
    putStrLn $ if is_prime n then "Yes" else "No"
    