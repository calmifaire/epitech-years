import System.Exit
import Data.List
import Data.Maybe
import Data.Char
import Data.String
import System.Environment

main :: IO ()
main = do
     args <- getArgs
     t <- getContents 
     checkEmpty args t
     pure ()

checkEmpty :: [String] -> String -> IO ()
checkEmpty [] t = exitWith (ExitFailure 84)
checkEmpty a t | all checkDigit (intercalate "" a) == True
                 = readCommand (stringToInt (intercalate " " a)) t
               | otherwise = exitWith (ExitFailure 84)

checkDigit :: Char -> Bool
checkDigit '-' = True
checkDigit x = isDigit x

stringToInt :: String -> [Int]
stringToInt x = map read $ words x :: [Int]

readCommand :: [Int] -> String -> IO ()
readCommand x t = whichSwap (x,[]) (words t)

whichSwap :: ([Int],[Int]) -> [String] -> IO ()
whichSwap (x,y) [] = checkSorted (x,y)
whichSwap (x,y) ("sa":sx) = whichSwap (applySwap x,y) sx
whichSwap (x,y) ("sb":sx) = whichSwap (x, applySwap y) sx
whichSwap (x,y) ("sc":sx) = whichSwap (applySwap x, applySwap y) sx
whichSwap x t = whichPush x t

whichPush :: ([Int],[Int]) -> [String] -> IO ()
whichPush x ("pa":sx) = whichSwap (applyPushA x) sx
whichPush x ("pb":sx) = whichSwap (applyPushB x) sx
whichPush x t = whichRotateEnd x t

whichRotateEnd :: ([Int],[Int]) -> [String] -> IO ()
whichRotateEnd (x,y) ("ra":sx) = whichSwap (rotateEnd x,y) sx
whichRotateEnd (x,y) ("rb":sx) = whichSwap (x,rotateEnd y) sx
whichRotateEnd (x,y) ("rr":sx) = whichSwap (rotateEnd x, rotateEnd y) sx
whichRotateEnd x t = whichRotateBegin x t

whichRotateBegin :: ([Int],[Int]) -> [String] -> IO ()
whichRotateBegin (x,y) ("rra":sx) = whichSwap (rotateBegin x,y) sx
whichRotateBegin (x,y) ("rrb":sx) = whichSwap (x,rotateBegin y) sx
whichRotateBegin (x,y) ("rrr":sx) = whichSwap (rotateBegin x, rotateBegin y) sx
whichRotateBegin (x,y) (_:_) = exitWith (ExitFailure 84)

rotateEnd :: [Int] -> [Int]
rotateEnd (x:[]) = (x:[])
rotateEnd x = (tail x ++ [head x])

applyPushA :: ([Int],[Int]) -> ([Int],[Int])
applyPushA (x,[]) = (x,[])
applyPushA (x,y) = ([head y] ++ x, tail y)

applyPushB :: ([Int],[Int]) -> ([Int],[Int])
applyPushB ([],y) = ([],y)
applyPushB (x,y) = (tail x, [head x] ++ y)

applySwap :: [Int] -> [Int]
applySwap (x:[]) = (x:[])
applySwap [] = []
applySwap (x:y:xs) = (y:x:xs)

rotateBegin :: [Int] -> [Int]
rotateBegin (x:[]) = (x:[])
rotateBegin x = ([last x] ++ [head x] ++ (tail x \\ [last x]))

checkSorted :: ([Int],[Int]) -> IO ()
checkSorted (x,[]) | sorted x == True = putStrLn "OK"
                   | otherwise = putStrLn "KO"
checkSorted (x,y) = putStrLn "KO"

sorted :: (Ord a) => [a] -> Bool
sorted [x] = True
sorted (x:y:xs) | x <= y = sorted (y:xs)
                | otherwise = False