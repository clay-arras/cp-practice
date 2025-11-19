

this problem can be divided into counting four orthogonal/ non overlapping
subproblems, and we return the answer by summing across all the subproblems.
overlaps can be divided into two types, with type 1 being when two intervals
OVERLAP, and type 2 being when an interval is ENCOMPASSED by another

implementation detail:
- need to coordinate compress the ranges, and merge lists S and S+K, E and E-K
- merge ALL of S, S+K, E, E-K. for each i, we should be able to identify S, Sk,
  E, Ek's ordering (just use the cc map).
- unordered map called cc that maps L/R[i] -> cc range


## type 1s:
use a segTree storing the starts of every interval. we process endpoints in
reverse sorted order. for each interval, we query the range [Si, Ei-ki], then
put the start point in the segTree

```
   ....
    ---------
-------
```


## type 1e
loop through starting points, sorted. query the range [Si+ki, Ei], and then put
your endpoint in the segTree
```
        .....
---------
    ---------
```


## type 2i
this is the hardest type of subproblem, since we don't know if the elements in
the range are SMALLER than the minimum k

<!-- processing orders: -->
<!-- - endpoints / start points: guarantees it's type 2i, no size guarantee -->
<!-- - sizes of R-L, K: vice versa -->

<!-- idea: segTree stores lengths of ranges. we process in the order of line sweep. -->
<!-- we add a point in the segTree when processing start, and remove it when -->
<!-- processing end. querying [ki, N] at the end will query the number of intervals -->
<!-- that are greater than length ki -->

<!-- we need to process BIGGER starts and SMALLER ends first -->

for this, we need to do two things. a) we need to put all k's (pair, -index)
and all R-L's into a list, and sort them. b) we need to have a segtree for end
points and start points


## type 2o
process start points in sorted order. for each interval, query [Ei, N-1] and
put the endpoint in the segTree. this works because by processing the start
points in sorted order, we guarantee that all elements in the segTree have
earlier start times, and the segTree guarantees we query later end times
```
   ....
-----------
   ----
```
