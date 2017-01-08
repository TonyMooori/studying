-- これ実装してく
-- http://vipprog.net/wiki/exercise.html

-- ループ練習
times 0 s = ""
times n s = (s++"\n") ++ (times (n-1) s)

times_ 0 action = return ()
times_ n action = action >> times_ (n-1) action

main = do
    putStr $ times 5 "Hello World!"
    putStrLn "-----------------------"
    putStr $ "12345" >> "Hello World!\n"
    putStrLn "-----------------------"
    5 `times_` (putStrLn "Hello World!")