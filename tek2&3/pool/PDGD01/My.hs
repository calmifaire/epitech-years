mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x
     | x < 0 = True
     | otherwise = False

myAbs :: Int -> Int
myAbs x
      | x < 0 = -x
      | otherwise = x

myMin :: Int -> Int -> Int
myMin x y
      | x < y = x
      | otherwise = y

myMax :: Int -> Int -> Int
myMax x  y
      |  x > y = x
      |  otherwise = y

myTuple :: a -> b -> (a, b)
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b , c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead (x:_) = x
myHead [] = error "empty list"

myTail :: [a] -> [a]
myTail (x:xs) = xs
myTail [] = error "empty list"

myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth  []      _ = error "out of range"
myNth (x : xs) 0 = x
myNth (_ : xs) n = myNth xs (n - 1)

myTake :: Int -> [a] -> [a]
myTake 0 x = []
myTake n (x:xs) | myLength xs == 0 = [x]
                | otherwise = x : myTake (n - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop _ [] = []
myDrop n xs@(_:xs')
       | n > 0 = myDrop (n-1) xs'
       | otherwise = xs

myAppend :: [a] -> [a] -> [a]
myAppend [] x = x
myAppend (x:xs) y = x : myAppend xs y

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [a] -> [a]
myInit [] = error "empty list"
myInit (x:xs) | myLength xs == 0 = xs
              | otherwise = x: myTake (myLength xs - 1) xs

myLast :: [a] -> a
myLast [] = error "empty list"
myLast (x:xs) | myLength xs == 0 = x
              | otherwise = myHead (myReverse xs)

myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x,y) : myZip xs ys

myUnzip :: [(a,b)] -> ([a], [b])
myUnzip [] = ([],[])
myUnzip xs = (myMap myFst xs, myMap mySnd xs)

myMap :: (a -> b) -> [a] -> [b]
myMap f [] = []
myMap f (x:xs) = f x : myMap f xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter f [] = []
myFilter f (x:xs) | f x == True = x : myFilter f xs
                  | otherwise = myFilter f xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl f z []     = z
myFoldl f z (x:xs) = myFoldl f (f z x) xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr f z []     = z
myFoldr f z (x:xs) = f x (myFoldr f z xs)