
{-# OPTIONS_GHC -Wall #-}

isAllSame :: Eq a => [a] -> Bool
isAllSame [] = True
isAllSame [_] = True
isAllSame (x:y:ys) = (x == y) && isAllSame (y:ys)

main :: IO ()
main = do
    print (isAllSame "AAAA")
    print (isAllSame [1, 1, 1, 2])
    print (isAllSame [1, 1, 1, 1])
