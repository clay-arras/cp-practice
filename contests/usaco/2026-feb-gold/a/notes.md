
## observation
observation: for any given pair of A[i] and B[i], then after performing K
operations on them, their imbalance is defined as 

(A[i] - B[i]) - 2k


## simplification
lets assume for simplicity that A is fixed. then, we can focus on optimizing
the right side of the equation, A - min(B). we can do this by binary searching
over threshold t, where we assert that every B[i] can be bought above t

thus, we sum over max(0, t - B[i]) and assert that this number is <= K

---

D = A - K'
C = A + B

then we want to minimize: max(D) + max(D - C)
define the total that D can be as T
note that D will be negative numbers


## theorem: 
we can optimize D - C before we optimize D, because to improve D by one we need
at least N operations, while to improve D - C by one we need strictly less

therefore, lets optimize the first N/2 positions. if we have K leftover, then
the new improvement will be N / K_left

---

assume we don't fill in C at all, and we only use operation 2.
<!-- ans = max(D - C) -->

this algorithm is split into two stages: filling in the excess with D - C by
adding negative values of D to the beginning N/2 elements.
