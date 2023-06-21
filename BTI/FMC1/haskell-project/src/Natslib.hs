module Natslib where

import System.Environment

data Nat = Z | S Nat
  deriving Show

add :: Nat -> Nat -> Nat
add n Z = n
add n (S m) = S (add n m)

mul :: Nat -> Nat -> Nat
mul n Z = Z
mul n (S m) = add (mul n m) n

pow :: Nat -> Nat -> Nat
pow n Z = S Z
pow n (S m) = mul (pow n m) n

pd :: Nat -> Nat
pd Z = Z
pd (S n) = n

sub :: Nat -> Nat -> Nat
sub n Z = n
sub n (S m) = pd(sub n m)

fact :: Nat -> Nat
fact Z = S Z
fact (S n) = mul (S n) (fact n)

fib :: Nat -> Nat 
fib Z = Z
fib (S Z) = S Z
fib (S (S n)) = add (fib (S n)) (fib n) 

pos :: Nat -> Nat
pos Z = Z
pos (S m) = S Z

quoc :: (Nat, Nat) -> Nat
quoc (Z, S n) = Z
quoc (S m, S n) = add (quoc (sub (S m) (S n), S n)) (mul (S Z) (pos (sub (S (S m)) (S n)))) 


res :: (Nat, Nat) -> Nat
res (Z, S n) = Z
res (S m, S n) = sub (S m) (mul (quoc (S m, S n)) (S n))

divs :: (Nat, Nat) -> (Nat, Nat)
divs (m, S n) = (quoc (m, S n), res (m, S n))

