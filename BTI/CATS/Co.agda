{-# OPTIONS --guardedness #-}

module Co where

open import Data.Nat
  renaming (zero to O; suc to S)

open import Data.Product
  renaming (proj₁ to outl; proj₂ to outr)
  hiding (zip; map)

open import Data.Sum
  renaming (inj₁ to inl; inj₂ to inr)
  hiding (map)

open import Data.Bool

open import Data.List
  using (List; [_]; []; _∷_)

----------------------------------------------------------------

record Stream (A : Set) : Set where
  coinductive
  field
    hd : A
    tl : Stream A

open Stream


map : {A B : Set} → (f : A → B) → Stream A → Stream B
map = {!!}

only : {A : Set} → (a : A) → Stream A
only = {!!}

genfibs : ℕ → ℕ → Stream ℕ
genfibs = {!!}

fibs : Stream ℕ
fibs = {!!}

lucs : Stream ℕ
lucs = {!!}

interleaved mutual

  evens : {A : Set} → Stream A → Stream A
  odds  : {A : Set} → Stream A → Stream A

  evens = {!!}
  odds = {!!}

merge : {A : Set} → Stream A → Stream A → Stream A
merge = {!!}

merge₃ : {A : Set} → Stream A → Stream A → Stream A → Stream A
merge₃ = {!!}

merge₂,₁ : {A : Set} → Stream A → Stream A → Stream A
merge₂,₁ = {!!}

drop : {A : Set} → ℕ → Stream A → Stream A
drop = {!!}

takeList : {A : Set} → ℕ → Stream A → List A
takeList = {!!}

zip : {A B : Set} → Stream A → Stream B → Stream (A × B)
zip = {!!}

zipWith : {A B C : Set} → (f : A → B → C) → Stream A → Stream B → Stream C
zipWith = {!!}

takeStep : {A : Set} → ℕ → Stream A → Stream A
takeStep = {!!}

upFrom : ℕ → Stream ℕ
upFrom = {!!}

downFrom : ℕ → Stream ℕ
downFrom = {!!}

preConcat : {A : Set} → ℕ → Stream A → Stream A → Stream A
preConcat = {!!}

insertAt : {A : Set} → ℕ → (w : A) → Stream A → Stream A
insertAt = {!!}

