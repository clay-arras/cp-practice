## subproblem #1: solution for NO queries

observation: you can split the biggest, non-chosen votes in half. i.e., if you
choose i and j as the leaders, we can split by vi, vj

therefore, vi + vj must be GREATER than or equal to the BIGGEST vx not chosen

- case 1: we choose the biggest vi. then we can choose any vj
- case 2: we do not choose the biggest v, so vi + vj >= vmax


feels like a segtree: 
- want to MAXIMIZE or MINIMIZE i
- want to SATISFICE the condition that vi + vj >= vmax OR vi >= vmax - vj

solution: store the segtree with stree[vi] = i, and query over max/min

time complexity: NlogN

---


idea: in some data structure, store all the values AND the query index they are
part of. this way, we can passively get the biggest query values

note: a query only changes TWO cost sums. decreasing the one its replacing and
increasing the one its adding too. also, there are several cases

- we increment the max
- we decrement the max
- we increment a leader
- we decrement a leader
... (we don't care)

note: it DEFINITELY has to do with the fact that the cost array only changes a
little bit at a time


---

assume we have a priority queue that stores N items. for each N item, it stores
the MAXIMUM diversity while being bigger than some max

--- 
simplifying the problem

- want to MAXIMIZE or MINIMIZE i
- want to SATISFICE the condition that vi + vj >= vmax OR vi >= vmax - vj
- we want DYNAMIC updates on the cost array

--- 

assume we store 2N frequencies mapping the changes. 
{v, i, q} // count, index, query
