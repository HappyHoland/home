{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
module Natslib where

import System.Environment

import qualified Prelude as P
import Data.Bifoldable (biall)
import Data.Bits (Bits(xor))

data Bool = True | False

data Nat = O | S Nat
  deriving (P.Show)

data List a = Empty | Cons a (List a)

data Tree a = Null | Node a (Tree a) (Tree a)

data Maybe a = Nothing | Just a

(+) :: Nat -> Nat -> Nat
n + O = n
n + (S m) = S (n + m)

(*) :: Nat -> Nat -> Nat
_ * O = O
n * (S m) = n + (n * m)

(^) :: Nat -> Nat -> Nat
_ ^ O = S O
n ^ (S m) = n * (n ^ m)

pd :: Nat -> Nat
pd O = O
pd (S n) = n

(∸) :: Nat -> Nat -> Nat
n ∸ O = n
n ∸ (S m) = pd(n ∸ m)

fact :: Nat -> Nat
fact O = S O
fact (S n) = S n * fact n

fib :: Nat -> Nat 
fib O = O
fib (S O) = S O
fib (S (S n)) = fib (S n) + fib n 

quot :: (Nat, Nat) -> Nat
quot (n, O) = O
quot (O, S n) = O
quot (S m, S n) = quot (S m ∸ S n, S n) + (S O ∸ (S n ∸ S m)) 

rem :: (Nat, Nat) -> Nat
rem (n, O) = O
rem (O, S n) = O
rem (S m, S n) = S m ∸ (quot (S m, S n) * S n)

div :: (Nat, Nat) -> (Nat, Nat)
div (m, n) = (quot (m, S n), rem (m, S n))

mod :: Nat -> Nat -> Nat
mod m n = rem(n, m)

gcd :: (Nat, Nat) -> Nat
gcd (n, O) = n
gcd (O, m) = m
gcd (S n, S m) = gcd (rem (S n, S m), rem (S m, S n))

lcm :: (Nat, Nat) -> Nat
lcm (n, O) = O
lcm (O, m) = O
lcm (S n, S m) = (gcd (S n, S m) * quot (S n, gcd (S n, S m))) * quot (S m, gcd (S n, S m))

comb :: Nat -> Nat -> Nat
comb n p = quot (fact n, fact p * fact (n ∸ p)) * (S O ∸ (p ∸ n))

perm :: Nat -> Nat -> Nat
perm n p = quot (fact n, fact (n ∸ p)) * (S O ∸ (p ∸ n))

(⇈) :: Nat -> Nat -> Nat
_ ⇈ O = S O
n ⇈ S m = n ^ (n ⇈ m)

and :: Bool -> Bool -> Bool
_ `and` False = False
b `and` True = b

or :: Bool -> Bool -> Bool
_ `or` True = True
b `or` False = b

not :: Bool -> Bool
not True = False
not False = True

(≤) :: Nat -> Nat -> Bool
O ≤ n = True
S m ≤ O = False
S m ≤ S n = m ≤ n

leq :: Maybe Nat -> Maybe Nat -> Bool
h `leq` Nothing = True
Nothing `leq` h = True
Just n `leq` Just m = n ≤ m

(==) :: Nat -> Nat -> Bool
O == O = True
O == S n = False
S m == O = False
S m == S n = m == n

isMul3 :: Nat -> Bool
isMul3 O = True
isMul3 (S (S (S n))) = isMul3 n
isMul3 (S n) = False

isEven :: Nat -> Bool
isEven O = True
isEven (S O) = False
isEven (S (S n)) = isEven n

isOdd :: Nat -> Bool
isOdd n = Natslib.not (isEven n)

length :: List Nat -> Nat
length Empty = O
length (Cons n l) = length l + S O

instance P.Show a => P.Show (List a) where 
  show Empty = "]"
  show (Cons a l) = P.show a P.++ ", " P.++ P.show l 

elem :: Nat -> List Nat -> Bool 
elem n Empty = False
elem n (Cons x l) = n == x `or` elem n l

sum :: List Nat -> Nat
sum Empty = O
sum (Cons n l) = n + sum l

product :: List Nat -> Nat
product Empty = S O
product (Cons n l) = n * product l

(++) :: List a -> List a -> List a
Empty ++ l = l
(Cons x l) ++ l' =  Cons x (l ++ l')

reverse :: List Nat -> List Nat
reverse Empty = Empty
reverse (Cons x l) = reverse l ++ Cons x Empty 

min :: Nat -> Nat -> Nat
min n O = O
min O m = O
min (S n) (S m) = S O + min n m

max :: Nat -> Nat -> Nat
max n O = n
max O m = m
max (S n) (S m) = S O + max n m

allEven :: List Nat -> Bool
allEven Empty = True
allEven (Cons n l) = isEven n `and` allEven l

anyEven :: List Nat -> Bool
anyEven Empty = False
anyEven (Cons n l) = isEven n `or` anyEven l

allOdd :: List Nat -> Bool
allOdd l = Natslib.not (anyEven l)

anyOdd :: List Nat -> Bool
anyOdd l = Natslib.not (allEven l)

ifthenelse :: Bool -> a -> a -> a
ifthenelse True a a' = a
ifthenelse False a a' = a'

isZero :: Nat -> Bool
isZero O = True
isZero (S n) = False

allZero :: List Nat -> Bool
allZero Empty = True
allZero (Cons n l) = isZero n `and` allZero l

anyZero :: List Nat -> Bool
anyZero Empty = False
anyZero (Cons n l) = isZero n `or` anyZero l

addNat :: Nat -> List Nat -> List Nat
addNat n Empty = Empty
addNat n (Cons x l) = Cons (x + n) (addNat n l)

multNat :: Nat -> List Nat -> List Nat
multNat n Empty = Empty
multNat n (Cons x l) = Cons (x * n) (addNat n l)

expNat :: Nat -> List Nat -> List Nat
expNat n Empty = Empty
expNat n (Cons x l) = Cons (x ^ n) (addNat n l)

enumFromTo :: Nat -> Nat -> List Nat
enumFromTo n m = ifthenelse (n ≤ m) (Cons n (enumFromTo (S n) m)) Empty

enumTo :: Nat -> List Nat
enumTo O = Cons O Empty
enumTo (S n) = Cons (S n) (enumTo n)

take :: Nat -> List Nat -> List Nat
take O l = Empty
take n Empty = Empty
take (S n) (Cons m l) = Cons m (take n l)

drop :: Nat -> List Nat -> List Nat 
drop O l = l
drop n Empty = Empty
drop (S n) (Cons m l) = drop n l

elemIndices :: Nat -> List Nat -> List Nat
elemIndices n Empty = Empty
elemIndices n (Cons m l) = ifthenelse (n == m) (Cons O (addNat (S O) (elemIndices n l))) (addNat (S O) (elemIndices n l))

pwAdd :: List Nat -> List Nat -> List Nat
pwAdd l Empty = Empty
pwAdd Empty l = Empty
pwAdd (Cons n l) (Cons m l') = ifthenelse (length l == length l') (Cons (n + m) (pwAdd l l')) Empty

pwMult :: List Nat -> List Nat -> List Nat
pwMult l Empty = Empty
pwMult Empty l = Empty
pwMult (Cons n l) (Cons m l') = ifthenelse (length l == length l') (Cons (n * m) (pwMult l l')) Empty

isSorted :: List Nat -> Bool
isSorted Empty = True
isSorted (Cons n Empty) = True
isSorted (Cons n (Cons m l)) = n ≤ m `and` isSorted l

filterEven :: List Nat -> List Nat
filterEven Empty = Empty
filterEven (Cons n l) = ifthenelse (isEven n) (Cons n (filterEven l)) (filterEven l)

filterOdd :: List Nat -> List Nat
filterOdd Empty = Empty
filterOdd (Cons n l) = ifthenelse (isOdd n) (Cons n (filterOdd l)) (filterOdd l)

minimum :: List Nat -> Maybe Nat
minimum Empty = Nothing
minimum (Cons n Empty) = Just n
minimum (Cons n (Cons m l)) = ifthenelse (Just n `leq` minimum (Cons m l)) (Just n) (minimum (Cons m l))

maximum :: List Nat -> Maybe Nat
maximum Empty = Nothing
maximum (Cons n Empty) = Just n
maximum (Cons n (Cons m l)) = ifthenelse (maximum (Cons m l) `leq` Just n) (Just n) (maximum (Cons m l))

isPrefixOf :: List Nat -> List Nat -> Bool
empty `isPrefixOf` l = True
(Cons x l) `isPrefixOf` Empty = False
(Cons x l) `isPrefixOf` (Cons y m) = (x == y) `and` (l `isPrefixOf` m) 

mix :: List Nat -> List Nat -> List Nat
empty `mix` l = l
(Cons x l) `mix` empty = Cons x l
(Cons x l) `mix` (Cons x' l') = Cons x (Cons x' (l `mix` l'))

intersperse :: Nat -> List Nat -> List Nat
intersperse n Empty = Empty
intersperse n (Cons x Empty) = Cons x Empty
intersperse n (Cons x (Cons y l)) = Cons x (Cons n (intersperse n (Cons y l)))

andList :: List Bool -> Bool 
andList Empty = True
andList (Cons x l) = x `and` andList l

orList :: List Bool -> Bool
orList Empty = False
orList (Cons x l) = x `and` orList l

replicate :: Nat -> a -> List a
replicate O x = Empty
replicate (S n) x = Cons x (replicate n x)

map :: (a -> b) -> List a -> List b
map f Empty = Empty
map f (Cons x l) = Cons (f x) (map f l)

concat :: List (List a) -> List a
concat Empty = Empty
concat (Cons x l) = x ++ concat l

all :: (a -> Bool) -> List a -> Bool
all p Empty = True
all p (Cons x l) = p x `and` all p l

any :: (a -> Bool) -> List a -> Bool
any p Empty = False
any p (Cons x l) = p x `or` any p l

filter :: (a -> Bool) -> List a -> List a
filter f Empty = Empty
filter f (Cons x l) = ifthenelse (f x) (Cons x (filter f l)) (filter f l)

pointwise :: (a -> a -> a) -> List a -> List a -> List a
pointwise r Empty l = Empty
pointwise r l Empty = Empty
pointwise r (Cons x l) (Cons x' l') = Cons (r x x') (pointwise r l l')

fold :: (a -> a -> a) -> a -> List a -> a
fold f x Empty = x
fold f x (Cons x' l) = f x (fold f x' l)