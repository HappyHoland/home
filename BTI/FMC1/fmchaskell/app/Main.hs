module Main where

import qualified Prelude as P

import Natslib

listX :: List Nat
listX = Cons (S O) (Cons (S (S O)) (Cons (S O) Empty))

lenListX :: Nat
lenListX = length listX

main :: P.IO ()
main = do
  P.print listX
  P.print lenListX
  P.print (sum listX)
  P.print (elemIndices (S O) listX)