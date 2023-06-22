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
hd (map f σ) = f (hd σ)
tl (map f σ) = map f (tl σ)

only : {A : Set} → (a : A) → Stream A
hd (only a) = a
tl (only a) = only a

genfibs : ℕ → ℕ → Stream ℕ
hd (genfibs n m) = n
tl (genfibs n m) = genfibs m (n + m)

fibs : Stream ℕ
fibs = genfibs 0 1

lucs : Stream ℕ
lucs = genfibs 0 2

-- interleaved mutual

 -- evens : {A : Set} → Stream A → Stream A
 -- odds : {A : Set} → Stream A → Stream A

merge : {A : Set} → Stream A → Stream A → Stream A
hd (merge σ τ) = hd σ
tl (merge σ τ) = merge τ (tl σ)

merge₃ : {A : Set} → Stream A → Stream A → Stream A → Stream A
hd (merge₃ σ τ ω) = hd σ
tl (merge₃ σ τ ω) = merge₃ τ ω (tl σ)

merge₂,₁ : {A : Set} → Stream A → Stream A → Stream A
merge₂,₁ = {!!}

drop : {A : Set} → ℕ → Stream A → Stream A
hd (drop O σ) = hd (tl σ)
tl (drop O σ) = tl (tl σ)
hd (drop (S n) σ) = hd σ
tl (drop (S n) σ) = drop n (tl σ)

takeList : {A : Set} → ℕ → Stream A → List A
takeList O σ = []
takeList (S n) σ = hd σ ∷ takeList n (tl σ)

zip : {A B : Set} → Stream A → Stream B → Stream (A × B)
hd (zip α β) = (hd α , hd β)
tl (zip α β) = zip (tl α) (tl β)

zipWith : {A B C : Set} → (f : A → B → C) → Stream A → Stream B → Stream C
hd (zipWith f σ τ) = f (hd σ) (hd τ)
tl (zipWith f σ τ) = zipWith f (tl σ) (tl τ)

takeStep : {A : Set} → ℕ → Stream A → Stream A
takeStep O σ =  σ
hd (takeStep (S n) σ) = hd (takeStep n (tl σ))
tl (takeStep (S n) σ) = tl (takeStep n (tl σ))

upFrom : ℕ → Stream ℕ
hd (upFrom n) = n
tl (upFrom n) = upFrom (S n)

downFrom : ℕ → Stream ℕ
hd (downFrom O) = O
tl (downFrom O) = downFrom O
hd (downFrom (S n)) = S n
tl (downFrom (S n)) = downFrom n

preConcat : {A : Set} → ℕ → Stream A → Stream A → Stream A
preConcat O σ τ = τ
hd (preConcat (S n) σ τ) = hd σ
tl (preConcat (S n) σ τ) = preConcat n (tl σ) τ

insertAt : {A : Set} → ℕ → (w : A) → Stream A → Stream A
hd (insertAt O w σ) = w
tl (insertAt O w σ) = σ
hd (insertAt (S n) w σ) = hd σ
tl (insertAt (S n) w σ) = insertAt n w (tl σ)

