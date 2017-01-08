-- これ実装してく
-- http://vipprog.net/wiki/exercise.html

-- うるう年測定

isUruu n 
 | n `mod` 400 == 0 = True
 | n `mod` 100 == 0 = False
 | n `mod` 4   == 0 = True
 | otherwise        = False

main = do
    n <- readLn
    putStrLn $ if isUruu n then "うるう年" else "うるう年じゃない"