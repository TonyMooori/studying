-- これ実装してく
-- http://vipprog.net/wiki/exercise.html

-- FizzBuzz 

fizzbuzz :: Int -> String
fizzbuzz n
    | n `mod` 15 == 0 = "Fizz Buzz"
    | n `mod` 3 == 0 = "Fizz"
    | n `mod` 5 == 0 = "Buzz"
    | otherwise = show n

main = do
    let fizzbuzz_words = map fizzbuzz [1..100]
    
    putStrLn $ foldl (\x y -> x ++ "\n" ++ y ) "" fizzbuzz_words