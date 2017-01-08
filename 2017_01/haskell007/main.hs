
primes :: [Int]
primes = sieve [2..]

-- リストの頭は素数，それ以降の数列はpの倍数を取り除く
sieve :: [Int] -> [Int]
sieve (p:xs) = p : sieve [x|x<-xs , x `mod` p /= 0]

fibs :: [Integer]
fibs = [ a+b | (a,b) <- zip (0:1:fibs) ( 0:fibs) ]

main = do
    print $ take 10 primes
    print $ take 10 fibs