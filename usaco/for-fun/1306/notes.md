
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

