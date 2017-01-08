type Parser a = String -> [(a,String)]

-- analyzing is always sucess
return_ :: a -> Parser a
return_ v = \inp -> [(v,inp)]


-- analyzing is always failure
failure :: Parser a
failure = \inp -> []


-- use first character of input string
item :: Parser Char
item = \inp -> case inp of
    [] -> []
    (x:xs) -> [(x,xs)]


-- apply parser 
parse :: Parser a -> String -> [(a,String)]
parse p inp = p inp


p :: Parser (Char,Char)
p = do
    x <- item
    item
    y <- item
    return (x,y)


main = do
    print $ parse (return_ 1) "abc"
    print $ parse (failure :: Parser Char) "abc"
    print $ parse item ""
    print $ parse item "abc"
    
    print $ parse p "abcdef"

