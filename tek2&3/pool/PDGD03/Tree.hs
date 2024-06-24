data Tree a = Empty
          | Node (Tree a) (a) (Tree a) deriving (Read, Eq, Show)

addInTree :: (Ord a) => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node left a right)
    | x < a = Node (addInTree x left) a right
    | x >= a = Node left a (addInTree x right)

instance Functor Tree where
  fmap f Empty = Empty
  fmap f (Node left x right) = Node (fmap f left) (f x) (fmap f right)

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = addInTree x (listToTree xs)