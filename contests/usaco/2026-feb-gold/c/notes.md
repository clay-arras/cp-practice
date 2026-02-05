lets say we simplify the question s.t. we only have cycles (no branches)

in that case, then our answer at each node is the position of the FIRST farmer
behind Bessie relative to Bessie. we can calculate this by unrooting each cycle
and doing a simple search.

---

if Bessie is on a branch, then its the first farmer behind Bessie
if Bessie is in a loop, then 
