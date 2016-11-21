
showline = putStrLn "-----------------------------------"


fac n = if n == 0 then 1 else n * fac (n-1)
doubleMe x = x + x

main :: IO ()
main = do
    -- calculate the factorial
    showline
    print $ fac 1
    print $ fac 2
    print $ fac 3
    print $ fac 4
    
    -- print function test
    showline
    print 1
    print True
    print False
    
    -- LYHGG
    print $ succ 8
    print $ min 9 20
    print $ min 3.4 3.2
    print $ max 100 101
    print $ doubleMe 9
    
    showline
    
    let lostNumbers = [4,8,15,16,23,42]
    print $ lostNumbers
    print $ "hello" ++ " " ++ "world"
    print $ [0,1]++[1,3]
    
    showline
    print $ 'A':" SMALL CAT"
    print $ 5:[1,2,3,4,5]
    