
if we assume that a given subtree has already been rooted at `r`, then we can
check if each node contributes to the interesting count by just checking if the
subtree size is greater than K. if the subtree is greater than K, then we can
just construct an LCA at that point by picking `r` and any K-1 numbers of a
subtree

the problem lies in the fact we cannot root at every node AND dfs over it, as
it will easily TLE

---

solution: 


