
-- 5.7.2
replicate_ :: Int -> a -> [a]
replicate_ n a = [ a | _ <- [1..n] ]

-- 5.7.3 x^2+y^2==z^2
pyths n = [(x,y,z) | x <- [1..n], y <- [1..n], z <- [1..n], x^2+y^2==z^2]

-- 5.7.4
factors n = [ x | x <- [1..n] , n `mod` x == 0  ]

perfects n = [ x | x <- [1..n] , 2*x == sum ( factors x ) ]

-- 5.7.6
find :: Eq a => a -> [(a,b)] -> [b]
find key pairs = [ y | (x,y) <- pairs , x == key ]

positions val list = find val $ zip list [0..length list - 1]

-- 5.7.7
scalarproduct lhs rhs = sum [ (lhs!!i) * (rhs!!i) | i <- [0..length lhs-1]]

main = do
    -- 5.7.1
    print $ sum [ x^2 | x <- [1..100] ]
    
    -- 5.7.2
    print $ replicate_ 3 True
    
    -- 5.7.3
    print $ pyths 10
    
    -- 5.7.4
    print $ factors 6
    print $ perfects 500
    
    -- 5.7.5
    print $ [ (x,y) | x <- [1..3] , y <- [4..6]]
    print $ concat [ [ (x,y) | y <- [4..6] ] | x <- [1..3 ]]
    
    -- 5.7.6
    print $ positions False [True,False,True,False]
    
    -- 5.7.7
    print $ scalarproduct [1..3] [4..6]