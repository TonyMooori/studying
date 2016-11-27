-- factorial
factorial n = product $ take n [1..]

-- average
average xs = sum xs `div` length xs

-- last
last_0 = head . reverse

last_1 (x:[]) = x
last_1 (x:xs) = last_1 xs

main = do
    let n = 10
    print $ head $ take n [1..]
    print $ tail $ take n [1..]
    print $ [1,2,3,4,5] !! 2
    print $ drop 3 $ take n [1..]
    print $ length [1..5]
    print $ sum [1..5]
    print $ product [1..5]
--    print $ 1 `div` 0
--    print $ head []
    print $ factorial 5
    print $ factorial 6
    print $ average [1,2,3,4,5,6]
    print $ average [5,6,6,6]
    print $ last_0 [1..5]
    print $ last_1 [1..5]