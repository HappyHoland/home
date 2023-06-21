module Main where

import Natslib

result :: (Nat, Nat)
result = divs (S (S (S (S Z))), S (S Z))

main :: IO ()
main = do
  print (result)