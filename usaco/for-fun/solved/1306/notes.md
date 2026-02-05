
<!---
## subproblem #1
lets focus on T=0 for now, because it's the easier subproblem

this problem can be split up into two components: the first is
calculating the minimum amount of time to fertilize each pasture, and
the second is to calculate the minimum amount of fertilizer needed.

we notice that the traversal of the farmer always forms a loop.
additionally, we notice that this loop is always deterministic. we
assert that the size of this loop is always `2(N-1)`

to calculate the minimum amount of fertilizer, we can use euler tour to
flatten the tree, rooted at the first pasture. assume that using euler
tour, we now have an array S, where the Si represents the sum of all the
ai in that subtree. we observe that it's ALWAYS optimal to traverse the
subtrees with larger Si first, since that will contribute to the most
cost. then, we can traverse the tree, where at each node, we traverse
the edge with the largest to smallest Si. the cost will be incremented
s.t. it's the dot product of iota and Si

this will take NlogN time.

EDGE CASE: consider a chain vs a web. the greedy doesn't differentiate but the
web will take more cost

CONSOLIDATION: this means that you have to dp on trees using the euler tour
flattening. we know exactly how much time it will take to process a subtree of
size K (it will be `2(K-1)`); therefore, we check for every single ordering
what the cost is for the main dp

therefore dp[i] should represent the minimum cost to process the ith subtree




## subproblem #2
notice that for T=1, the difference is that instead of ending at the
start node, it's ALWAYS optimal to end at the node thats FURTHEST away
from the start node. if there are multiple such nodes, we have to check
each one.

--->

lets solve subproblem T=0 first. for this, there are a couple of things we need
to keep track of. dp[i] is the minimum cost to traverse this subtree. we also
need a way to quickly the sum of all the Ais in a certain subtree, and a way to
keep track of how large a certain subtree is.

at each local node when we are traversing, the correct way is to SORT BY the
sum of Ais in that subtree. we go down the BIGGEST first, then the second
biggest, etc.

observations: 
- the sizes of the subtrees can vary. we would prefer to go down smaller
  subtrees first
- the sum of costs in a subtree can vary. we would prefer to go down bigger
  cost-sum subtrees first
- the in-practice traversal dp cost can vary

for each one, we have:
- dp practical traversal cost + subtree-sum * time-elapsed
- time elapsed is a prefix of all the subtree sizes


define dp[i] as the minimum COST it takes to traverse this subtree and
fertilize all the pastures. hence, the sum equals 

`dp[i] + tree.query(st[i], en[i]) * pref`
base case: dp[i] = A[i]

- additionally, we need to topologically sort the inputs so we process leaves
  first. the dp base case is that we have ???

---

ok. so for T = 1, we need a way to consolidate multiple long ones. define a
long one as a path of a tree s.t. it has the furthest distance from the root.
if there are multiple such long ones, we always want to end at one of them;
however, if there's a tie, then we know that we always want to end at the long
one with the SMALLEST cost. so if there's a tie between long ones, choose the
one with the smallest cost, and then filter s.t. we process that long one LAST.
else, default to the original dp values.





















