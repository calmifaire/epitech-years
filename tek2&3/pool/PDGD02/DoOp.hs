import Data.Maybe
import Data.Char
import System.Exit
import System.Environment
import Control.Monad

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem a (x:xs) = a == x || myElem a xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv a b = Just (div a b)

safeNth :: [a] -> Int -> Maybe a
safeNth  []      _ = Nothing
safeNth (x : xs) 0 = Just x
safeNth (_ : xs) n = safeNth xs (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = Just (x + 1)

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup _ [] = Nothing
myLookup a ((x,y):xs) | a == x = Just y
                      | otherwise = myLookup a xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo f Nothing _ = Nothing
maybeDo f _ Nothing = Nothing
maybeDo f (Just a) (Just b) = Just (f a b)

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt s | all isDigit (tail s) == False = Nothing
          | otherwise = Just (read s)

getLineLength :: IO Int
getLineLength = do
              line <- getLine
              return $ length line

printAndGetLength :: String -> IO Int
printAndGetLength s = putStrLn s >>
                    return (length s)

duplicate :: [a] -> Int -> [a]
duplicate dup n = concat $ replicate n dup

lineD :: Int -> IO ()
lineD n | n < 1 = pure ()
        |otherwise = putStr "+" >>
                   (putStr $ duplicate "-" (n-2)) >>
                   (putStrLn "+") >>
                   (repeatL ((div n 2)-2) n)

lineE :: Int -> IO ()
lineE n = putStr "+" >>
         (putStr $ duplicate "-" (n-2)) >>
         (putStrLn "+")

printBox :: Int -> IO ()
printBox 1 = putStrLn "++\n++"
printBox n = lineD (n * 2)

repeatL :: Int -> Int -> IO ()
repeatL 0 m = lineE m
repeatL n m  = putStr "|" >>
               (putStr $ duplicate " " (m-2)) >>
               (putStrLn "|") >>
               (repeatL (n-1) m)

readNLines :: Int -> IO String
readNLines n = liftM concat (replicateM n getLine)

getInt :: IO (Maybe Int)
getInt = do
        s <- getLine
        return $ readInt s 
