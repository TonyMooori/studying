-- summation
mysum [] = 0
mysum (x:xs) = x + mysum xs

-- quick sort
qsort [] = []
qsort (x:xs) = qsort smaller ++ [x] ++ qsort larger
    where
        smaller = [ a | a <- xs ,  a <= x ]
        larger = [ a | a <- xs , a > x ]

-- product 
prod [] = 1
prod (x:xs) = x * prod xs

-- reverse list
rev [] = []
rev (x:xs) = rev xs ++ [x]

-- revesed qsort
qsort_rev = rev . qsort 

main = do
    let n = 5
    
    print $ mysum $ take n $ [1..]
    print $ qsort [2,6,7,3,8,9,54,8,8,8,5,8,9,99,34]
    print $ sum . filter even $ take n [1..]
    print $ sum [ a | a <- take n [1..] , even a ]
    print $ sum [ a | a <- take n [1..] , odd a ]
    print $ foldl (*) 1 $ take n [1..]
    print $ prod $ take n [1..]
    print $ prod [2,3,4]
    print $ qsort [3,2,5]
    print $ qsort_rev [3,2,5]