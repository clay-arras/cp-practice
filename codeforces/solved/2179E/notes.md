
we have a certain quota X, Y to hit. 
we draw up the MINIMUM SUMS we need each element to hit s.t. they stay winning
- e.g. pi = 3, then ai = 2 and bi = 1
- e.g. pi = 4, then ai = 3 and bi = 1

ai can be MORE, but it can't be less than this value. likewise, bi can be MORE
but not equal to or greater than ai

the SUMS of all the minimum values of all the winning districts have to be LESS
than the quotas X, Y
this is assuming that both parties have won at least once

### formalization
lets define the MINIMUM sum for an element to hit is ceil((p[i] + 1) * 1.0 / 2)
the MAXIMUM for a party to stay losing is min_p - 1

if each party wins at least once, our only check is the sum of all the minsums
for each winning party is less than or equal to the quota



## edge cases:
if one party wins all the elections, then we also have to count the MAXIMUM
value the LOSING party can be because we can always go less

---
core lemmas: the winning parties can always go more and the losing parties can
always go less. therefore, the sum of all the minimums of the winning parties
have to be less than the quotas, and the sum of the losing parties have to be
more.

however, this is tricky because we can also have (assuming `a` won)
extra = X - sum min_a
sum max_b + extra has to be >= Y
