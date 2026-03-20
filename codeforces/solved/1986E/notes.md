
this can be split into two cases: the even case and the odd case.

## N is even case
we notice that no array element can reach another array element if they have
different modulo Ks. so we create a hashmap that maps from modulo of K, to the
list of elements. we can then sort those elements and take naive pairings of
them to find the answer.


## N is odd case
we notice that at most ONE out of all the elements in the hashmap can have odd
length. we will need to calculate this separately.

to calculate which one removed will have the minimum cost, we can dp this.
define `dp[i][1]` as the minimum cost to fully cover up to index i, where x is
if we skipped or not

```
dp[i][1] = dp[i-1][0]
dp[i][1] = dp[i-2][1] + (A[i] - A[i-1])/K
dp[i][0] = dp[i-2][0] + (A[i] - A[i-1])/K
```

note: start with 1 indexing
