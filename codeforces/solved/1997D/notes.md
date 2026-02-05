

theory 1: binary search over a good value for the root. 
then we can directly search over the graph and try to get each child to ABOVE that threshold greedily
using euler tour, difference array, and segment tree

when at the leaves, we just check if they're nonnegative
don't actually need a euler tour + segtree, can just pass a rolling count in the dfs



steps: 
- at root, we want to bridge the DIFFERENCE from A[x] to k
- at every other parent node, we want to bridge the difference between (A[x]-acc) to 0
