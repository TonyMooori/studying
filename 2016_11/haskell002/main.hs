import Control.Applicative
import Control.Monad
import System.IO


fac n = foldl (*) 1 [1.0,2.0..n]
func x = foldl (+) 1 $ map (\n -> (x ** n) / fac n ) [1..9]


main :: IO()
main = do
    n_temp <- getLine
    let n_line = read n_temp :: Int
    
    forM_ [1..n_line] $ \a0  -> do
        x_temp <- getLine
        let x = read x_temp :: Double
        putStrLn $ show $ func x