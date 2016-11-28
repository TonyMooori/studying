
-- example of if, else
abs_ :: Int -> Int
abs_ n = if n >= 0 then n else -n

signum_ :: Int -> Int
signum_ n = if n < 0 then -1 else if n == 0 then 0 else 1

-- example of guards
abs__ n
    | n >= 0 = n
    | otherwise = -n

signum__ n
    | n > 0     = 1
    | n==0      = 0
    | otherwise = -1

-- example of pattern match
not_ True = False
not_ False = True

and_ True True = True
and_ _  _  = False

fst_ (x,_) = x
snd_ (_,x) = x

three_a_first ['a',_,_] = True
three_a_first _ = False

null_ [] = True
null_ _ = False
head_ (x:xs) = x
tail_ (x:xs) = xs

-- example of lambda eq
odds_ n = map (\x -> x*2+1) [0..n-1]
odds__ n = map f [0..n-1]
    where f = \x -> 2*x+1

halve xs = (map f [0..n-1], map f [n..m-1])
    where
        f = (\x -> xs !! x) 
        n = (length xs) `div` 2
        m = length xs

safetail_ [] = []
safetail_ (x:xs) = xs

safetail__ xs 
    | null xs = []
    | otherwise = map (\x->xs!!x) [1..length xs-1]

main = do
    -- 4.2 if,else
    print $ "4.2:"
    print $ abs_ (-5)
    print $ abs_ 515
    
    print $ signum_ (-157)
    print $ signum_ 115
    print $ signum_ 0
    
    -- 4.3 guards 
    print $ "4.3:"
    print $ abs__ (-177)
    print $ abs__ 16
    
    print $ signum__ (-18)
    print $ signum__ 11
    print $ signum__ 0
    
    -- 4.4 pattern match
    print $ "4.4:"
    print $ not_ True
    print $ not_ False
    print $ and_ False False
    print $ and_ True False
    print $ and_ True True
    print $ fst_ ("fst","snd")
    print $ snd_ ("fst","snd")
    print $ three_a_first "abc"
    print $ three_a_first "bcd"
    print $ head_ ["head","tail","tail"]
    print $ tail_ ["head","tail","tail"]
    print $ null_ ["head","tail","tail"]
    print $ null_ []
    
    -- 4.5 lambda eq.
    print $ (\x -> x + x ) 2
    print $ odds_ 5
    print $ odds__ 5
    
    -- 4.6 section
    print $ (+) 1 2
    print $ (+2) 2
    
    -- 4.8 
    print $ halve [1,2,3,4,5,6]
    print $ (safetail_ [1..6])
    print $ (safetail__ [1..6])