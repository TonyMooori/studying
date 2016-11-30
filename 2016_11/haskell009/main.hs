
-- factorial example 
factorial1 n = product [1..n]

factorial2 0 = 1
factorial2 n = n * factorial2 (n-1)

-- product sample
product_ [] = 1
product_ (x:xs) = x * product_ xs

-- length sample
length_ [] = 0
length_ (_:xs) = 1 + length xs

-- reverse sample
reverse_ [] = []
reverse_ (x:xs) = reverse_ xs ++ [x]

-- insert sample
insert x [] = [x]
insert x (y:ys) 
    | x >= y = [y] ++ insert x ys
    | otherwise = [x,y] ++ ys

-- insert sort sample
isort [] = []
isort (x:xs) = insert x $ isort xs

-- zip sample
zip_ _ [] = []
zip_ [] _ = []
zip_ (x:xs) (y:ys) = [(x,y)] ++ zip_ xs ys 

-- drop sample
drop_ n [] = []
drop_ 0 xs = xs
drop_ n (x:xs) = drop_ (n-1) xs

-- fibonacci sample
fib 0 = 1
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

-- quick sort sample
qsort [] = []
qsort (x:xs) = qsort lhs ++ [x] ++ qsort rhs
    where
        lhs = [ a | a <- xs , a <= x ]
        rhs = [ b | b <- xs , b > x  ]

-- odd,even sample
even_ 0 = True
even_ n = odd_ (n-1)

odd_ 0 = False
odd_ n = even_ (n-1)

-- get odd/even index value in list
evens [] = []
evens (x:xs) = [x] ++ odds xs

odds [] = []
odds (x:xs) = evens xs

-- power example
pow :: Integral a => a -> a -> a
pow x 0 = 1
pow x n = x * pow x (n-1)

-- and sample
and_ [] = True
and_ (x:xs) 
    | x == False = False
    | otherwise  = and_ xs

-- concat sample
concat_ [] = []
concat_ (x:xs) = x ++ concat_ xs

-- replicate sample
replicate_ 0 val = []
replicate_ n val = val:replicate_ (n-1) val

-- !! sample
--getIndex [] _ = 
getIndex (x:xs) 0 = x
getIndex (x:xs) n = getIndex xs (n-1)

-- elem sample
elem_ a [] = False
elem_ a (x:xs) 
    | x == a = True
    | otherwise = elem_ a xs

-- merge
merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge [] xs = xs
merge xs [] = xs
merge (x:xs) (y:ys) 
    | x < y     = [x] ++ merge xs (y:ys)
    | otherwise = [y] ++ merge (x:xs) ys

-- halve 
halve xs = (lhs,rhs)
    where 
        n = (length xs) `div` 2
        lhs = take n xs
        rhs = drop n xs

-- msort
msort :: Ord a => [a] -> [a]
msort [] = []
msort (x:[]) = [x]
msort xs = merge (msort $ fst t) (msort $ snd t)
    where   t = halve xs


main = do
    -- 6.1
    print $ factorial1 5
    print $ factorial2 5
    
    -- 6.2
    print $ product [3,5,7]
    print $ product_ [3,5,7]
    
    print $ length [3,5,7]
    print $ length_ [3,5,7]
    
    print $ reverse [1..5]
    print $ reverse_ [1..5]
    
    print $ insert 3 [1,2,4,5]
    
    print $ isort [3,5,7,1,9,5,2,5,7,3]
    
    -- 6.3
    print $ zip_ "hello" [1..5]
    
    print $ drop_ 2 [1..5]
    
    -- 6.4
    print $ map fib [0..10]
    print $ qsort  [3,5,7,1,9,5,2,5,7,3]
    
    -- 6.5
    print $ even_ 5
    print $ odd_ 5
    
    print $ evens [0..10]
    print $ odds  [0..10]
    
    -- 6.8
    print $ pow 2 10
    print $ and_ [True,False]
    print $ and_ [True,True]
    print $ concat_ [[1,2],[3,3,3]]
    print $ replicate_ 3 True
    print $ getIndex [0..5]  5
    print $ getIndex [0..5]  1
    print $ elem_ 1 [2..5]
    print $ elem_ 2 [2..5]
    print $ merge [2,100] [1,3,4]
    print $ halve [1..5]
    print $ halve [1..4]
    print $ msort [3,5,7,1,9,5,2,5,7,3]

