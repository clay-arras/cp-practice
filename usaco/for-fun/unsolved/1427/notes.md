
assume we are looping over every possible NUMBER of subarrays. then this
problem simplifies to how many ways we can split the two subarrays into
k subarrays s.t. ...


## PROBLEM

INVARIANT: if you have an average of a subarray, and you have another
average of an earlier subarray whose average is greater than this
average, then concatenating the two will strictly not decrease the total
subarray average



## SOLUTION

we can have prefix sums of averages of all subarrays

if there's some way of getting all suffixes that are greater than a
certain average, by storing them in a set or segment tree

obs: inner K and outer K have a lot of overlap (depending on whether
you're targeting K or K+1 subarrays)

assume that for every ENDPOINT in a subarray, we have a sorted list of
suffixes with their average. i.e. `vector<set<pair<long double, int>>>`

note: for each `dp[i][j][k]` we might need to sum along the counts for
sorted vector indices. assume we had a data structure to do this.

we definitely precalculate some information for the second array


QUESTION: what shape of the data can we preprocess the second array into
s.t. it'll be useful to us?
attempt: lets say we have `dp[i][k]` where it represents we can get 

PATTERN: unrolling loop pattern. if you have nested loops from a fixed
amount of data, then somehow unroll and precompute that into information
using less time than nested


### SHAPE 1

lets loop through K, N, N, K
K represents the number of total subarrays we want to split
N represents the index for the first array
N represents the index for the second array
K represents how many subarrays we've formed thus far


assume we have two arrays: `dp1[i][k]` and `dp2[j][k]`
also assume we have `vector<set<pair<long double, int>>> last`, which
represents an average, and the prefix sum of all the dps that this
satisfies

then lets say the dp1 has some average; in that case, we can update dp2
using the following formula: `dp[j][k+1] = sum dp[i][k]` where the sum
is the prefix sum we mentioned earlier.

### PROPOSAL: does there EXIST a way to split the subarrays into K
subarrays s.t. the constraints are satisfied (don't need to count)

`dp1[i][k]` says there exists a way to split the first array s.t. the
constraints are valid
`dp2[j][k]` says there exists a way to split the second array s.t. the
constraints are valid

assume we have an average from the first array. in that case, we can
check if `dp2[j][k]` is valid by checking for each element in last[j],
does there exist an element that is both larger than the average AND
their dp is exists (note: can simplify this by only adding if dp is
possible)
