import init.data.int.basic



axiom add_id_R (a: int):
  a + 0 = a

axiom add_assoc (a b c: int):
  a + (b+c) = (a+b) + c

axiom add_inv_R (a: int):
  a + (-a) = 0

axiom add_comm (a b: int):
  a + b = b + a

axiom mul_id_R (a: int):
  a*1 = a 

axiom mul_assoc (a b c: int):
  a*(b*c) = (a*b)*c

axiom mul_comm (a b: int):
  a*b = b*a

axiom mul_add (a b c: int):
  a*(b+c) = a*b + a*c

axiom NZD (a b: int):
  a*b = 0 ? a = 0 ? b = 0

axiom one_neq_zero:
  1 ? 0

axiom less_tric:
  ? a b: int, (a < b ? a ? b ? ¬(b < a)) ? (¬(a < b) ? a = b ? ¬(b < a)) ? (¬(a < b) ? a ? b ? b < a)

axiom less_trans:
  ?a b c: int, a < b ? b < c ? a < c

axiom less_add:
  ?a b c: int, a < b ? a + c < b + c

axiom less_mul:
  ?a b c: int, a < b ? c > 0 ? a*c < b*c

def divides (a b: int) := ?k:int, a*k = b
infix ` | `:55 := divides

def subtract (a b: int) := a + -b
infix ` - ` :55 := subtract

def abs (a: int) := if a < 0 then -a else a

def Pos (a: int) := a > 0

theorem add_id_L (a: int): 0 + a = a :=
  begin
    rw add_comm,
    rw add_id_R,
  end

theorem mul_id_L (a: int): 1*a = a :=
  begin
    have h1 := mul_comm(1)(a),
    rw h1,
    have h2 := mul_id_R(a),
    assumption,
  end

theorem add_inv_L (a: int): -a + a = 0 :=
  begin
    have h1 := add_inv_R(a),
    have h2 := add_comm(a)(-a),
    rw h2 at h1,
    assumption,
  end

theorem uni_add_id_0 (a: int): 
  (?b:int, a + b = a) ? (?b:int, a + b = a ? b = 0) :=
  begin
    split,
      existsi a+-a,
      have h := add_inv_R(a),
      have h1 := add_id_R(a),
      rw h,
      rw h1,

      intro b,
      intro h,
      have h1 := add_inv_R(a),
      have h2 := add_id_L(b),
      rw ? h1 at h2,
      have h3 := add_comm(a + -a)(b),
      rw h3 at h2,
      have h4 := add_assoc(b)(a)(-a),
      rw h4 at h2,
      have h5 := add_comm(b)(a),
      rw h5 at h2,
      rw h at h2,
      rw h1 at h2,
      rw h2,

  end

theorem right_add_eq_left_neg (a b c: int):
  a = b + c ? a + (-c) = b :=
  begin
    split,
      intro h,
      have h1 := add_inv_R(c),
      have h2 := add_id_R(b),
      rw ? h2,
      rw ? h1,
      rw h,
      have h3 := add_assoc(b)(c)(-c),
      rw h3,

      intro h,
      have h1 := add_id_R(a),
      have h2 := add_inv_R(c),
      rw ? h1,
      rw ? h2,
      have h3 := add_comm(c)(-c),
      rw h3,
      have h4 := add_assoc(a)(-c)(c),
      rw h4,
      rw h,
  end

theorem left_add_eq_right_neg (a b c : int):
  a + b = c ? a = c + -b :=
  begin
    split,
      intro h,
      have h1 := add_id_R(a),
      have h2 := add_inv_R(b),
      have h3 := add_assoc(a)(b)(-b),
      rw ? h1,
      rw ? h2,
      rw h3,
      rw h,

      intro h,
      have h1 := add_id_R(c),
      have h2 := add_inv_R(b),
      have h3 := add_comm(b)(-b),
      have h4 := add_assoc(c)(-b)(b),
      rw ? h1,
      rw ? h2,
      rw h,
      rw h3,
      rw h4,
  end

theorem add_cancel (b c : int):
  ?x : int, b + x = c + x ? b = c :=
  begin
    assume a,
    intro h,
    have h1 := right_add_eq_left_neg(b + a)(c)(a),
    have h3 := h1.1(h),
    have h4 := add_inv_R(a),
    have h5 := add_assoc(b)(a)(-a),
    rw ? h5 at h3,
    have h6 := add_comm(b)(a + -a),
    rw h6 at h3,
    rw h4 at h3,
    have h7 := add_id_L(b),
    rw h7 at h3,
    assumption,
  end

theorem eq_add (a b:int):
  ?x: int, a = b ? a + x = b + x :=
  begin
    assume c,
    intro h,
    rw h,
  end

theorem uni_add_inv (a: int):
  (?x:int, a + x = 0) ? (?x : int, a + x = 0 ? x = -a) :=
  begin
    split,
      existsi -a,
      have h := add_inv_R(a),
      assumption,

      assume b,
      intro h,
      have h1 := add_inv_R(a),
      rw ? h1 at h,
      have h2 := add_comm(a)(-a),
      have h3 := add_comm(a)(b),
      rw h2 at h,
      rw h3 at h,
      have h4 := add_cancel(b)(-a)(a),
      have h5 := h4(h),
      assumption,
  end

theorem zero_anul_R (x : int):
  x*0 = 0:=
  begin
    have h := mul_id_R(x),
    have h1 := add_id_R(1),
    rw ? h1 at h,
    have h2 := mul_add(x)(1)(0),
    rw h2 at h,
    have h3 := mul_id_R(x),
    rw h3 at h,
    have h4 := uni_add_id_0(x),
    cases h4 with h4e h4a,
    have h5 := h4a(x*0),
    have h6 := h5(h),
    assumption,
  end

theorem zero_anul_L (x: int):
  0*x = 0 :=
  begin
    have h := zero_anul_R(x),
    have h1 := mul_comm(x)(0),
    rw h1 at h,
    assumption,
  end

theorem neg_neg_eq_pos (x : int):
  x = -(-x) :=
  begin
    have h := add_inv_R(x),
    have h1 := left_add_eq_right_neg(x)(-x)(0),
    have h2 := h1.1(h),
    have h3 := add_id_L(-(-x)),
    rw h3 at h2,
    assumption,
  end

theorem mul_neg_1_eq_neg (x: int):
  -1*x = -x :=
  begin
    have h := zero_anul_R(x),
    have h1 := add_inv_R(1),
    rw ? h1 at h,
    have h2 := mul_add(x)(1)(-1),
    rw h2 at h,
    rw h1 at h,
    have h3 := uni_add_inv(x*1),
    cases h3 with h3e h3a,
    have h4 := h3a(x*-1),
    have h5 := h4(h),
    have h6 := mul_id_R(x),
    rw h6 at h5,
    have h7 := mul_comm(x)(-1),
    rw h7 at h5,
    assumption,
  end

theorem neq_mul_pos_eq_neg (x y:int):
  (-x)*y = -(x*y):=
  begin
    have h := mul_neg_1_eq_neg(x),
    rw ? h,
    have h1 := mul_assoc(-1)(x)(y),
    have h2 := mul_neg_1_eq_neg(x*y),
    rw ? h1,
    rw h2,
  end

theorem pos_mul_neg_eq_neg (x y: int):
  x*(-y) = -(x*y) := 
  begin
    have h := mul_neg_1_eq_neg(y),
    rw ? h,
    have h1 := mul_comm(x)((-1)*y),
    have h2 := mul_assoc(-1)(y)(x),
    have h3 := mul_neg_1_eq_neg(y*x),
    rw h1,
    rw ? h2,
    rw h3,
    have h4 := mul_comm(y)(x),
    rw h4,
  end

theorem neg_mul_neg_eq_pos (x y: int):
  (-x)*(-y) = x*y :=
  begin
    have h := neq_mul_pos_eq_neg(x)(-y),
    rw h,
    have h1 := pos_mul_neg_eq_neg(x)(y),
    rw h1,
    have h2 := neg_neg_eq_pos(x*y),
    rw ? h2,
  end

theorem mul_cancel (a b: int):
  ?x:int, (x ? 0) ? (a*x = b*x) ? a = b :=
  begin
    assume c,
    intro h,
    cases h with cnzero h1,
    have h2 := add_id_L(b*c),
    rw ? h2 at h1,
    have h3 := right_add_eq_left_neg(a*c)(0)(b*c),
    rw h3 at h1,
    have h4 := neq_mul_pos_eq_neg(b)(c),
    rw ? h4 at h1,
    have h5 := mul_comm(a)(c),
    have h6 := mul_comm(-b)(c),
    rw h5 at h1,
    rw h6 at h1,
    have h7 := mul_add(c)(a)(-b),
    rw ? h7 at h1,
    have h8 := NZD(c)(a + -b),
    have h9 := h8(h1),
    cases h9,
      have f := cnzero(h9),
      contradiction,
    
      have h10 := right_add_eq_left_neg(a)(0)(b),
      rw ? h10 at h9,
      have h11 := add_id_L(b),
      rw h11 at h9,
      assumption,
  end

theorem eq_mul (a b: int):
  ?x: int, a = b ? a*x = b*x :=
  begin
      assume c,
      intro h,
      rw h,
  end

theorem div_refl:
  ?a: int, a|a :=
  begin
    assume a,
    existsi a+-a+1,
    have h := add_inv_R(a),
    have h1 := add_id_L(1),
    have h2 := mul_id_R(a),
    rw h,
    rw h1,
    rw h2,
  end

theorem div_trans:
  ? a b c: int, a | b ? b | c ? a | c :=
  begin
    assume a b c,
    intro h,
    cases h with adivb bdivc,
    cases adivb with x hx,
    cases bdivc with y hy,
    existsi x*y,
    have h1 := mul_assoc(a)(x)(y),
    rw h1,
    rw hx,
    rw hy,
  end

theorem any_div_zero (a: int):
  a | 0 :=
  begin
    existsi a+-a,
    have h := add_inv_R(a),
    rw h,
    have h1 := zero_anul_R(a),
    assumption,
  end

theorem zero_div_only_zero:
  0 | 0 ? (?x: int, 0 | x ? x = 0):=
  begin
    split,
    have h := uni_add_inv(1),
    cases h with he ha,
    cases he with x hx,
    existsi x,
    have h1 := zero_anul_L(x),
    assumption,

    assume a,
    intro h,
    cases h with k h1,
    have h2 := zero_anul_L(k),
    rw h2 at h1,
    rw h1,
  end

theorem one_div_all (a: int):
  1 | a :=
  begin
    existsi a,
    have h := mul_id_L(a),
    assumption,
  end 

theorem neg_one_div_all (a: int):
  -1 | a :=
  begin
    existsi -a,
    have h := neg_mul_neg_eq_pos(1)(a),
    rw h,
    have h1 := mul_id_L(a),
    assumption,
  end 

theorem divs_both_divs_sum_of_multiples (d a b x y: int):
  d | a ? d | b ? d | a*x + b*y :=
  begin
    intro h,
    cases h with h1 h2,
    cases h1 with p hp,
    cases h2 with q hq,
    existsi p*x + q*y,
    have h3 := mul_add(d)(p*x)(q*y),
    rw h3,
    have h4 := mul_assoc(d)(p)(x),
    have h5 := mul_assoc(d)(q)(y),
    rw h4,
    rw hp,
    rw h5,
    rw hq,
  end

theorem uni_mul_id_1 (a : int): 
  (?x:int, a*x = a) ? (?x: int, a ? 0 ? a*x = a ? x = 1) :=
  begin
    split,
      existsi a+-a+1,
      have h := add_inv_R(a),
      have h1 := add_id_L(1),
      have h2 := mul_id_R(a),
      rw h,
      rw h1,
      assumption,

      assume b,
      intro h,
      cases h with anzero h1,
      have h2 := add_id_L(a),
      have h3 := right_add_eq_left_neg((0+a)*b)(0)(a),
      rw ? h2 at h1,
      rw h3 at h1,
      rw h2 at h1,
      have h4 := mul_neg_1_eq_neg(a),
      rw ? h4 at h1,
      have h5 := mul_comm(-1)(a),
      rw h5 at h1,
      have h6 := mul_add(a)(b)(-1),
      rw ? h6 at h1,
      have h7 := NZD(a)(b + -1),
      have h8 := h7(h1),
      cases h8,
        have f := anzero(h8),
        contradiction,

        have h9 := right_add_eq_left_neg(b)(0)(1),
        rw ? h9 at h8,
        have h10 := add_id_L(1),
        rw h10 at h8,
        assumption,
  end

theorem P_add_fech (a: int):
 a > 0 ? a + a > 0 :=
 begin
    intro h,
    have h1 := less_add(0)(a)(a),
    have h2 := h1(h),
    have h3 := add_id_L(a),
    rw h3 at h2,
    have h4 := less_trans(0)(a)(a+a),
    have h5 : 0 < a ? a < a + a,
      split,
        assumption,
        
        assumption,
    have h6 := h4(h5),
    assumption,
 end

theorem P_mul_fech (a: int):
  a > 0 ? a*a > 0 :=
  begin
    intro h,
    have h1 := less_mul(0)(a)(a),
    have h2 : 0 < a ? a > 0,
      split,
        assumption,

        assumption,
    have h3 := h1(h2),
    have h4 := zero_anul_L(a),
    rw h4 at h3,
    assumption,
  end





theorem P_tric (a: int):
  (a > 0 ? a ? 0 ? ¬(-a > 0))?(¬(a > 0) ? a = 0 ? ¬(-a > 0))?(¬(a > 0) ? a ? 0 ? -a > 0) :=
  begin
    have h := less_tric(0)(a),
    cases h,
      left,
      cases h with h1 h2,
      cases h2 with h2 h3,
      split,
        assumption,

        split,
          intro x,
          apply h2,
          rw x,

          intro x,
          apply h3,
          sorry,
  end