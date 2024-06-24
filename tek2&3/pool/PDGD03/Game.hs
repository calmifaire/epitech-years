data Item = Sword | Bow | MagicWand
     deriving (Eq)

instance Show Item where
         show = showItem
         
showItem :: Item -> String
showItem Sword = "sword"
showItem Bow = "bow"
showItem MagicWand = "magic wand"

data Mob = Mummy | Skeleton Item | Witch (Maybe Item)
     deriving (Eq)

instance Show Mob where
         show = showMob

showMob :: Mob -> String
showMob Mummy = "mummy"
showMob (Skeleton MagicWand) = "skeleton holding a " ++ (show MagicWand)
showMob (Skeleton Bow) = "doomed archer"
showMob (Skeleton Sword) = "dead knight"
showMob (Witch (Just Sword)) = "witch holding a " ++ (show Sword)
showMob (Witch (Just Bow)) = "witch holding a " ++ (show Bow)
showMob (Witch (Just MagicWand)) = "sorceress"
showMob (Witch Nothing) = "witch"

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

createSkeleton :: Mob
createSkeleton = Skeleton MagicWand

createWitchHolding :: Item -> Mob
createWitchHolding a = Witch (Just a)

create :: String -> Maybe Mob
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "dead knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create a = Nothing

equip :: Item -> Mob -> Maybe Mob
equip Bow (Skeleton _) = Just createArcher
equip Sword (Skeleton _)  = Just createKnight
equip MagicWand (Skeleton _) = Just createSkeleton 
equip MagicWand (Witch (Just _)) = Just createSorceress
equip a (Witch (Just _)) = Just (createWitchHolding a)
equip MagicWand (Witch Nothing) = Just createSorceress
equip a (Witch Nothing) = Just (createWitchHolding a)
equip _ Mummy = Nothing

class HasItem a where
      getItem :: a -> Maybe Item;
      hasItem :: a -> Bool;
      hasItem a = case getItem a of
               Nothing -> False
               (Just _) -> True

instance HasItem Mob where
         getItem (Skeleton x) = (Just x)
         getItem (Witch Nothing) = Nothing
         getItem (Witch (Just x)) = (Just x)
         getItem Mummy = Nothing