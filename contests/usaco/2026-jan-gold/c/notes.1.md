
todo: formalize the DP definition and run through an example

[sum (2^j + 1)] - 1



---
some sort of memoization trick
assume that the ith coach covers j campers. then if the ith coach is selected,
any combination of campers can also be selected (2^j)

the problem arises when you have overlapping coaches
<!-- `dp[i][0] represents the last coach WAS selected` -->


## SIMPLIFICATION: lets assume NO overlapping coaches
in this case, then its the products of all the (2^js) that all the coaches
cover


## EXTENSION 1: lets assume coaches can only overlap ONCE (i.e. at most num
coaches for each camper is 2)

then there's two cases: if the last coach was selected, or if it wasn't
- if the last coach WASN'T SELECTED, then the answer is regular dp[i-2] * 2^j
- if the last coach WAS SELECTED, then the answer is dp[i-1] * 2^(j - o), where
  o is the number of overlapping campers


## EXTENSION 2: lets extend to the full problem now
lets keep track of the last coach that DOESN'T overlap with the current
processing using a single pointer
