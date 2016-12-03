import Data.Char

-- add function meaning
add_ x y = x + y
add__ = \x -> (\y -> x + y)

-- twice function
twice f x = f ( f x )

-- sum,product,or,and,length,reverse
sum_ = foldr (+) 0

-- product
product_ = foldr (*) 1

-- or
or_ :: [Bool] -> Bool
or_ = foldr (||) True

-- and
and_ :: [Bool] -> Bool
and_ = foldr (&&) True

-- length
length_ = foldr (\_ x -> x + 1) 0

-- reverse
reverse_ = foldr (\x y -> y++[x]) [] 

-- odd
odd_ = not . even 

type Bit = Int

-- binary to int
bin2int :: [Bit] -> Int
bin2int xs = sum [ w * x | (w,x) <- zip weights xs ]
    where   weights = iterate (*2) 1
-- bin2int = foldr (\x y -> x + 2 * y) 0

-- int to binary
int2bin 0 = []
int2bin n = (n`mod`2) : (int2bin $ n `div` 2)

-- make byte
make8 xs = take 8 ( xs ++ repeat 0 )

-- encode
encode :: String -> [Bit]
encode str = concat $ map (make8.int2bin.ord) str

-- decode
decode :: [Bit] -> String
decode [] = []
decode bits = ((chr.bin2int) $ take 8 bits) : (decode $ drop 8 bits)

-- dec2int
dec2int xs = foldl (\x y-> x * 10 + y) 0 xs

main = do
    -- 7.1
    print $ add_ 1 2
    print $ add__ 1 2
    print $ twice (+2) 1
    
    -- 7.2
    print $ map (+1) [1,3,5,7]
    print $ map isDigit "a1b2"
    print $ map reverse ["abc","def","ghi"]
    
    print $ filter even [1..10]
    print $ filter (>5) [1..10]
    print $ filter (/=' ') "abc def ghi"
    
    print $ sum( map (^2) ( filter even [1..10]) )
    
    -- 7.3
    print $ sum_ [1..5]
    print $ product_ [1..5]
    print $ length_ [1..5]
    print $ reverse_ [1..10]
    
    -- 7.5
    print $ odd_ 1
    print $ (sum . map (^2) . filter even) [1..10]

    -- 7.6
    print $ bin2int [1,0,1,1]
    print $ int2bin 13
    print $ (make8 . int2bin) 13
    print $ encode "Happy Haskelling"
    print $ decode $ encode "Happy Haskelling"
    
    -- 7.8
    --print $ map f $ filter p x
    print $ dec2int [2,3,4,5]
    