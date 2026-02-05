at each step, you can either delete the node or keep it

transitions:
- delete: then dp[i+1] + 1
- keep: then dp[i+A[i]]

dp definition: the minimum number of deletions to REACH this index
options: FROM JUMP
