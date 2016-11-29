import Data.Char

-- concat function example
concat_ :: [[a]] -> [a]
concat_ xss = [ x |  xs <- xss , x <- xs]

-- get first value of tuple list
firsts :: [(a,b)] -> [a]
firsts xs = [a | (a, _ ) <- xs]

-- get all factors of n
factors n = [ x | x <- [1..n] , n `mod` x == 0 ]

-- check is prime
is_prime n = [1,n] ==  factors n 

-- get all prime numbers under n
primes n = [ x | x <- [2..n] , is_prime x ]

-- make std::map
find key list = [ y | (x,y) <- list , x == key ]

-- get pairs 
pairs xs = zip xs $ tail xs

-- check is sorted
is_sorted xs = and [ a < b |  (a,b) <- (pairs xs) ]

-- get all x index
positions x xs = [ i | (y,i) <- zip xs [0..n] , x == y ]
        where n = (-1) + (length xs)

-- count lower character
lowers xs = length [ x | x <- xs , isLower x ]

-- count all charater of c
count_chara c str = length [ x | x <- str , c == x ]

-- Char -> Int conversion
let2int c = ord c - ord 'a'

-- Int -> Char conversion
int2let n = chr $ ord 'a' + n

-- caesar shift
shift n c
    | isLower c = int2let $ (n + let2int c) `mod` 26
    | otherwise = c
 
-- caesar encoding
encode n xs = [shift n x | x <- xs ]

-- table of frequency
table :: [Float]
table = [8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.2, 0.8, 4.0, 2.4, 6.7, 7.5,
         1.9, 0.1, 6.0, 6.3, 9.1, 2.8, 1.0, 2.4, 0.2, 2.0, 0.1]

-- percentage of n / m
percent n m = (fromIntegral n / fromIntegral m) * 100

-- get table of frequency of character
freqs :: [Char] -> [Float]
freqs xs = [ (percent (count_chara c xs ) (length xs)) | c <- ['a'..'z']]

-- differences of two vector
chisqr os es = sum [(x-y)**2 / y | (x,y) <- zip os es ]

-- rotate list
rotate n xs = (drop n xs) ++ (take n xs)

crack xs = encode (-factor) xs
    where 
        factor = head( positions (minimum chitab) chitab)
        chitab = [chisqr (rotate n freq_table) table | n <- [0..25]]
        freq_table = freqs xs

main = do
    -- 5.1
    print $ [ x^2 | x <-[1..5] ]
    print $ [ (x,y) | x <- [1..3] , y <- [3..6] ]
    print $ [ (x,y) | y <- [3..6] , x <- [1..3] ]
    print $ [ (x,y) | x <- [1..3] , y <- [x..3] ]    
    print $ concat_ [[1,2,3],[4,5,6]]
    print $ firsts [(1,2),(0,5)]
    
    -- 5.2
    print $ factors 240
    print $ is_prime 12
    print $ is_prime 13
    print $ primes 100
    print $ find "a" [("a",5),("b",3),("a",2)]
    
    -- 5.3
    print $ zip [1..4] $ tail [1..4]
    print $ is_sorted [1..10]
    print $ is_sorted $ [1..10] ++ [5]
    print $ positions 1 [0..10]
    
    -- 5.4
    print $ lowers "Haskell"
    print $ count_chara 's' "Mississippi"
    
    -- 5.5
    print $ shift 3 'z'
    print $ encode 3 "haskell is fun"
    print $ freqs "abbcccddddeeeee"
    print $ rotate 3 [1..5]
    print $ crack "kdvnhoo lv ixq"