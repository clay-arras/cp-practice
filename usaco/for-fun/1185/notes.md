
## ideas:

notes: N and H are very small. this is most likely a slow algorithm


**simplification #1**
assume that we loop over all hunger levels that we are ENDING on. this costs H
time, and simplifies the problem to the following: 
- what is the number of ways we can reduce the hunger levels to ZERO, given the
  upper bounds on the cow's hunger

---


**simplification #2**
assume that instead of H representing the UPPER bound on the cow's hunger,
assume it represents the EXACT of the cow's hunger. our problem now simplifies
to, given the cow's hunger levels, CAN WE REDUCE this to zero.

solution: we can GREEDILY reduce in O(N) time. this is because when we have the
array 

    [1, 4, 4, 8, 7]

we know the first cow NEEDS to eat with the second cow (there's no other
option), so we feed the two together

    [0, 3, 4, 8, 7] = [3, 4, 8, 7]

this simplifies to the first step


---
back to simplification #1:

somehow, there MUST be a way to DP over the array, where `dp[i][x]` represents
we are on the ith problem, and x represents the CURRENT hunger we achieved, and
the result represents the number of ways to achieve this state

there are invalid states here, so we init with -1. the base case is `dp[0] =
1`, and the transitions are `dp[i][y] ~ dp[i-1][x]`. if x >= y, then we
increment the number of ways for all valid x's. in this way, it makes sense to
use a diff array inside the dp.

`
for all i, y, x:
    dp[i][y-x] += dp[i-1][x]

`
