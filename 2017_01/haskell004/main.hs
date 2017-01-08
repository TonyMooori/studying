-- これ実装してく
-- http://vipprog.net/wiki/exercise.html

-- 平方根を求めてみる

-- ニュートン法
f :: Float -> Float -> Float
f n x = (x+n/x)*0.5

-- なんかニュートン法を繰り返してあれするかんじ
mySqrt :: Float -> Float
mySqrt n = g n
    where g = foldl (\x y -> x . y ) id (take 100 $ repeat (f n))


main = do
    x <- readLn
    print $ mySqrt x