
section propositional

variables P Q R : Prop


------------------------------------------------
-- Proposições de dupla negaço:
------------------------------------------------

theorem doubleneg_intro :
  P → ¬¬P  :=
begin
  intro p,
  intro np,
  apply np,
  exact p,
end

-- Usa LEM --
theorem doubleneg_elim :
  ¬¬P → P  :=
begin
  intro nnp,
  by_cases p : P,
  exact p,
  have n := nnp(p),
  exfalso,
  exact n,
end

-- Usa LEM --
theorem doubleneg_law :
  ¬¬P ↔ P  :=
begin
  split,
  intro nnp,
  have u := doubleneg_elim(P),
  have p := u(nnp),
  exact p,
  intro p,
  have h := doubleneg_intro(P),
  have nnp := h(p),
  exact nnp,
  
end

------------------------------------------------
-- Comutatividade dos ∨,∧:
------------------------------------------------

theorem disj_comm :
  (P ∨ Q) → (Q ∨ P)  :=
begin
  intro pq,
  cases pq,
  right,
  exact pq,
  left,
  exact pq,
end

theorem conj_comm :
  (P ∧ Q) → (Q ∧ P)  :=
begin
  intro pq,
  cases pq with p q,
  split,
  exact q,
  exact p,
end


------------------------------------------------
-- Proposições de interdefinabilidade dos →,∨:
------------------------------------------------

theorem impl_as_disj_converse :
  (¬P ∨ Q) → (P → Q)  :=
begin
  intro npq,
  intro p,
  cases npq,
  have f := npq(p),
  contradiction,
  assumption,
end

theorem disj_as_impl :
  (P ∨ Q) → (¬P → Q)  :=
begin
  intro pq,
  intro np,
  cases pq,
  have f := np(pq),
  contradiction,
  assumption,
end


------------------------------------------------
-- Proposições de contraposição:
------------------------------------------------

theorem impl_as_contrapositive :
  (P → Q) → (¬Q → ¬P)  :=
begin
  intro pq,
  intro nq,
  intro p,
  have q := pq(p),
  have f := nq(q),
  assumption,
end

-- Usa LEM --
theorem impl_as_contrapositive_converse :
  (¬Q → ¬P) → (P → Q)  :=
begin
  intro nqnp,
  intro p,
  by_cases q : Q,
  assumption,
  have np := nqnp(q),
  have f := np(p),
  contradiction,
end

-- Usa LEM --
theorem contrapositive_law :
  (P → Q) ↔ (¬Q → ¬P)  :=
begin
  split,
  have h := impl_as_contrapositive(P)(Q),
  assumption,
  have h := impl_as_contrapositive_converse(P)(Q),
  assumption,
end


------------------------------------------------
-- A irrefutabilidade do LEM:
------------------------------------------------

lemma create_disj1 :
  P → P∨Q :=
begin
  intro p,
  left,
  assumption,
end

theorem lem_irrefutable :
  ¬¬(P∨¬P)  :=
begin
  intro h,
  apply h,
  right,
  intro p,
  have p_or_np : P∨¬P,
  left,
  assumption,
  have f:= h(p_or_np),
  assumption,
end


------------------------------------------------
-- A lei de Peirce
------------------------------------------------

theorem peirce_law_weak :
  ((P → Q) → P) → ¬¬P  :=
begin
  intros h np,
  apply np,
  apply h,
  intro p,
  have f := np(p),
  contradiction,
end


------------------------------------------------
-- Proposições de interdefinabilidade dos ∨,∧:
------------------------------------------------

theorem disj_as_negconj :
  P∨Q → ¬(¬P∧¬Q)  :=
begin
  intro pq,
  intro npnq,
  cases npnq with np nq,
  cases pq,
  have f := np(pq),
  assumption,
  have f := nq(pq),
  assumption,
end

theorem conj_as_negdisj :
  P∧Q → ¬(¬P∨¬Q)  :=
begin
  intro pq,
  intro npnq,
  cases pq with p q,
  cases npnq,
  have f:= npnq(p),
  assumption,
  have f:= npnq(q),
  assumption,
end


------------------------------------------------
-- As leis de De Morgan para ∨,∧:
------------------------------------------------

lemma create_disj :
  P → P∨Q :=
  begin
    intro p,
    left,
    assumption,
  end

theorem demorgan_disj :
  ¬(P∨Q) → (¬P ∧ ¬Q)  :=
begin
  intro h,
  split,
  
  intro p,
  have h1 := create_disj(P)(Q),
  have pq := h1(p),
  have f := h(pq),
  assumption,

  intro q,
  have h1 := create_disj(Q)(P),
  have qp := h1(q),
  have h2 := disj_comm(Q)(P),
  have pq := h2(qp),
  have f := h(pq),
  assumption,
end

theorem demorgan_disj_converse :
  (¬P ∧ ¬Q) → ¬(P∨Q)  :=
begin
  intro h,
  intro u,
  cases h with np nq,
  cases u,
  
  have f := np(u),
  assumption,

  have f := nq(u),
  assumption,

end

lemma create_conj :
  P → (Q → P∧Q) :=
begin
  intro p,
  intro q,
  split,
  assumption,
  assumption,
end

-- Usa LEM --
theorem demorgan_conj :
  ¬(P∧Q) → (¬Q ∨ ¬P)  :=
begin
  intro h,
  by_cases p : P; by_cases q : Q,
  have h1 := create_conj(P)(Q),
  have qpq := h1(p),
  have h2 := qpq(q),
  have f := h(h2),
  contradiction,

  left,
  assumption,

  right,
  assumption,

  right,
  assumption,
end

theorem demorgan_conj_converse :
  (¬Q ∨ ¬P) → ¬(P∧Q)  :=
begin
  intro h1,
  intro h2,
  cases h2 with p q,
  cases h1,
  have f := h1(q),
  assumption,
  have f := h1(p),
  assumption,
end

-- Usa LEM --
theorem demorgan_conj_law :
  ¬(P∧Q) ↔ (¬Q ∨ ¬P)  :=
begin
  split,
  have h1 := demorgan_conj(P)(Q),
  assumption,
  have h2 := demorgan_conj_converse(P)(Q),
  assumption,
end

theorem demorgan_disj_law :
  ¬(P∨Q) ↔ (¬P ∧ ¬Q)  :=
begin
  split,
  have h1 := demorgan_disj(P)(Q),
  assumption,
  have h2 := demorgan_disj_converse(P)(Q),
  assumption,
end

------------------------------------------------
-- Proposições de distributividade dos ∨,∧:
------------------------------------------------

theorem distr_conj_disj :
  P∧(Q∨R) → (P∧Q)∨(P∧R)  :=
begin
  intro h,
  cases h with p qr,
  cases qr,
    left,
    split,
      assumption,
    
      assumption,
    
    right,
    split,
      assumption,
      
      assumption,
end

theorem distr_conj_disj_converse :
  (P∧Q)∨(P∧R) → P∧(Q∨R)  :=
begin
  intro h,
  cases h,
    cases h with p q,
    split,
      assumption,

      left,
      assumption,
    
    cases h with p r,
    split,
      assumption,

      right,
      assumption,
end

theorem distr_disj_conj :
  P∨(Q∧R) → (P∨Q)∧(P∨R)  :=
begin
  intro h,
  cases h,
    split,
      left,
      assumption,

      left,
      assumption,
    
    cases h with q r,
    split,
      right,
      assumption,

      right,
      assumption,
end

theorem distr_disj_conj_converse :
  (P∨Q)∧(P∨R) → P∨(Q∧R)  :=
begin
  intro h,
  cases h with pq pr,
  cases pq,
    left, 
    assumption,

    cases pr,
      left,
      assumption,

      right,
      split,
        assumption,

        assumption,
end


------------------------------------------------
-- Currificação
------------------------------------------------

theorem curry_prop :
  ((P∧Q)→R) → (P→(Q→R))  :=
begin
  intros h p q,
  have aux := create_conj(P)(Q),
  have aux1 := aux(p),
  have pq := aux1(q),
  have r := h(pq),
  assumption,
end

theorem uncurry_prop :
  (P→(Q→R)) → ((P∧Q)→R)  :=
begin
  intros h pq,
  cases pq with p q,
  have qr := h(p),
  have r := qr(q),
  assumption,
end


------------------------------------------------
-- Reflexividade da →:
------------------------------------------------

theorem impl_refl :
  P → P  :=
begin
  intro p,
  assumption,
end

------------------------------------------------
-- Weakening and contraction:
------------------------------------------------

theorem weaken_disj_right :
  P → (P∨Q)  :=
begin
  intro p,
  left,
  assumption,
end

theorem weaken_disj_left :
  Q → (P∨Q)  :=
begin
  intro q,
  right,
  assumption,
end

theorem weaken_conj_right :
  (P∧Q) → P  :=
begin
  intro pq,
  cases pq with p q,
  assumption,
end

theorem weaken_conj_left :
  (P∧Q) → Q  :=
begin
  intro pq,
  cases pq with p q,
  assumption,
end

theorem conj_idempot :
  (P∧P) ↔ P :=
begin
  split,
    intro pp,
    cases pp with p p,
    assumption,

    intro p,
    split,
      assumption,

      assumption,
end

theorem disj_idempot :
  (P∨P) ↔ P  :=
begin
  split,
    intro pp,
    cases pp,
      assumption,

      assumption,
    
    intro p,
    left,
    assumption,
end

end propositional


----------------------------------------------------------------


section predicate

variable U : Type
variables P Q : U -> Prop


------------------------------------------------
-- As leis de De Morgan para ∃,∀:
------------------------------------------------

theorem demorgan_exists :
  ¬(∃x, P x) → (∀x, ¬P x)  :=
begin
  intro h,
  intro a,
  intro pa,
  apply h,
  existsi a,
  assumption,

end

theorem demorgan_exists_converse :
  (∀x, ¬P x) → ¬(∃x, P x)  :=
begin
  intro h,
  intro h1,
  cases h1 with a pa,
  have npa := h(a),
  have f := npa(pa),
  assumption,
end

-- Usa RAA --
theorem demorgan_forall :
  ¬(∀x, P x) → (∃x, ¬P x)  :=
begin
  intro h,
  by_contradiction n,
  apply h,
  assume a,
  by_contradiction x,
  apply n,
  existsi a,
  exact x,
end

theorem demorgan_forall_converse :
  (∃x, ¬P x) → ¬(∀x, P x)  :=
begin
  intros he ha,
  cases he with x npx,
  have px := ha(x),
  have f := npx(px),
  assumption,
end

-- Usa RAA --
theorem demorgan_forall_law :
  ¬(∀x, P x) ↔ (∃x, ¬P x)  :=
begin
  split,
    have f:= demorgan_forall(U)(P),
    assumption,

    have f:= demorgan_forall_converse(U)(P),
    assumption,
end

theorem demorgan_exists_law :
  ¬(∃x, P x) ↔ (∀x, ¬P x)  :=
begin
  split,
    have f:= demorgan_exists(U)(P),
    assumption,

    have f:= demorgan_exists_converse(U)(P),
    assumption,
end


------------------------------------------------
-- Proposições de interdefinabilidade dos ∃,∀:
------------------------------------------------

theorem exists_as_neg_forall :
  (∃x, P x) → ¬(∀x, ¬P x)  :=
begin
  intros he ha,
  cases he with u pu,
  have npu := ha(u),
  have f := npu(pu),
  assumption,
end

theorem forall_as_neg_exists :
  (∀x, P x) → ¬(∃x, ¬P x)  :=
begin
  intros ha he,
  cases he with u npu,
  have pu:= ha(u),
  have f:= npu(pu),
  assumption,
end

-- Usa RAA --
theorem forall_as_neg_exists_converse :
  ¬(∃x, ¬P x) → (∀x, P x)  :=
begin
  intro he,
  assume a,
  by_contradiction npa,
  apply he,
  existsi a,
  assumption,
end

-- Usa RAA --
theorem exists_as_neg_forall_converse :
  ¬(∀x, ¬P x) → (∃x, P x)  :=
begin
  intro ha,
  by_contradiction he,
  apply ha,
  assume a,
  intro pa,
  apply he,
  existsi a,
  assumption,
end

-- Usa RAA --
theorem forall_as_neg_exists_law :
  (∀x, P x) ↔ ¬(∃x, ¬P x)  :=
begin
  split,
    have h:= forall_as_neg_exists(U)(P),
    assumption,

    have h:= forall_as_neg_exists_converse(U)(P),
    assumption,
end

-- Usa RAA --
theorem exists_as_neg_forall_law :
  (∃x, P x) ↔ ¬(∀x, ¬P x)  :=
begin
  split,
    have h:= exists_as_neg_forall(U)(P),
    assumption,

    have h:= exists_as_neg_forall_converse(U)(P),
    assumption,
end


------------------------------------------------
--  Proposições de distributividade de quantificadores:
------------------------------------------------

theorem exists_conj_as_conj_exists :
  (∃x, P x ∧ Q x) → (∃x, P x) ∧ (∃x, Q x)  :=
begin
  intro h,
  cases h with x hx,
  cases hx with px qx,
  split,
    existsi x,
    assumption,

    existsi x,
    assumption,

end

theorem exists_disj_as_disj_exists :
  (∃x, P x ∨ Q x) → (∃x, P x) ∨ (∃x, Q x)  :=
begin
  intro h,
  cases h with x hx,
  cases hx,
    left,
    existsi x,
    assumption,

    right,
    existsi x,
    assumption,
end

theorem exists_disj_as_disj_exists_converse :
  (∃x, P x) ∨ (∃x, Q x) → (∃x, P x ∨ Q x)  :=
begin
  intro h,
  cases h,
    cases h with x px,
    existsi x,
    left,
    assumption,

    cases h with x qx,
    existsi x,
    right,
    assumption,
end

theorem forall_conj_as_conj_forall :
  (∀x, P x ∧ Q x) → (∀x, P x) ∧ (∀x, Q x)  :=
begin
  intro h,
  split,
    assume a,
    have paqa := h(a),
    cases paqa with pa qa,
    assumption,

    assume a,
    have paqa := h(a),
    cases paqa with pa qa,
    assumption,
end

theorem forall_conj_as_conj_forall_converse :
  (∀x, P x) ∧ (∀x, Q x) → (∀x, P x ∧ Q x)  :=
begin
  intro h,
  cases h with p q,
  assume a,
  split,
    have pa := p(a),
    assumption,

    have qa := q(a),
    assumption, 
end


theorem forall_disj_as_disj_forall_converse :
  (∀x, P x) ∨ (∀x, Q x) → (∀x, P x ∨ Q x)  :=
begin
  intro h,
  cases h with p q,
    assume a,
    have pa := p(a),
    left,
    assumption,

    assume a,
    have qa := q(a),
    right,
    assumption,
end


/- NOT THEOREMS --------------------------------

theorem forall_disj_as_disj_forall :
  (∀x, P x ∨ Q x) → (∀x, P x) ∨ (∀x, Q x)  :=
begin
end

theorem exists_conj_as_conj_exists_converse :
  (∃x, P x) ∧ (∃x, Q x) → (∃x, P x ∧ Q x)  :=
begin
end

---------------------------------------------- -/

end predicate
