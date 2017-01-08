-- パーサー :   関数
-- 引数     :   文字列
-- 返り値   :   結果と文字列
type Parser a = String -> [(a,String)]

-- 文字列を消費せずvを結果として返す関数
return_ :: a -> Parser a
return_ v = \inp -> [(v,inp)]

-- 失敗するパーサー
failure :: Parser a
failure = \inp -> []

-- 入力文字列が空なら失敗，あれば文字列を消費して結果として返す
item :: Parser Char
item = \inp ->  if inp == "" then [] 
                else [(head inp,tail inp)]

-- パーサーを適用する関数
parse :: Parser a -> String -> [(a,String)]
parse p inp = p inp

-- pが成功したらその結果を，失敗したらqを適用した結果を返す
(+++) :: Parser a -> Parser a -> Parser a
(+++) p q = \inp -> case parse p inp of
    [] -> parse q inp
    [(v,out)] -> [(v,out)]
{-
isDigit :: Char -> Bool
isDigit c = or [c == x | x <- "0123456789"]

-- Char -> Bool の関数を受取りTrueなら取り出す
sat :: (Char -> Bool) -> Parser Char
sat p = do  x <- item
            if p x then return x else failure

-- 
digit :: Parser Char
digit = sat isDigit
-}


main = do
    print $ parse (return_ 1) "abc"
    print $ parse (failure :: Parser Char) "abc"
    print $ parse (item) "abc"
    print $ parse (item +++ (return_ 'd')) "abc"
    print $ parse (failure +++ (return_ 'd')) "abc"
    print $ parse (failure +++ failure :: Parser Char) "abc"
    
    -- バージョンアップで全然コンパイル通らんので無限にムッスーってなってる
    -- 僕は諦めました，いつか新しい本を買ってやる日を夢見てます
