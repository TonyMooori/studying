
-- A sample of definition of function
is_digit :: Char -> Bool
is_digit c = or $ map (==c) "0123456789"

-- polymorphic function sample
zip_ :: [a] -> [b] -> [(a,b)]
zip_ (x:[]) (y:[]) = [(x,y)]
zip_ (x:xs) (y:ys) = [(x,y)] ++ zip_ xs ys

main = do
    print $ not True
    print $ not False
    print $ (1 :: Float)
    print $ (1 :: Integer )
    print $ (1 :: Int)
    
    -- is_digit check
    print $ is_digit 'A'
    print $ is_digit '1'
    
    -- zip_check
    print $ zip_ [1,2,3,4,5,6] "ABCDEF"
    
    {-
        基本クラス
        Eq  
            同等クラス・
            ==,/=
            Bool,Char,String,Int,[Int],[String]等
            
        Ord
            順序クラス．Eqクラスのインスタンス．
            <,<=,>,>=,min,max
            Bool,Char,String,Int,[Int],[String]等
        
        Show
            表示可能クラス．
            show
            Bool,Char,String,Int,[Int],[String]等
        
        Read
            読み込み可能クラス
            read
            Bool,Char,String,Int,[Int],[String]等
        
        Num
            数値クラス．Eqクラス，Showクラスのインスタンス．
            +,-,*,negate,abs,signum
            Bool,Char,String,Int等
        
        Integral
            整数クラス．Numクラスのインスタンス．
            div,mod
            
        Read
            読み込み可能クラス
            read
            Int,Integer等
        
        Fractional
            分数クラス．Numクラスのインスタンス．
            /,reicp
            Float等
    -}