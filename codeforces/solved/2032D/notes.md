
*motivation*: we can use the constraint that if x <= y, then px <= py to aggressively narrow
down candidates using a form of pseudo binary search / divide and conquer

---
ideas:

<!-- lets take a number i that is at index exactly n/2 -->
<!-- the parent of this must be approximately in the range `[0, n/2]` (aka processes n/2) -->

<!-- lets say we find this point somewhere at j. assume we take the number at index -->
<!-- exactly n/4. --> 
<!-- we'll have to search the space to the left of it, which is at most n/4 items -->
<!-- (turns out to be in the range [0, min(n/4, j)]) -->

<!-- now lets say we have the number at index 3n/4. for this to be valid, it has to -->
<!-- be in the range [j, n/2] -->

---

to find out how many tentacles there are, loop through i until i and 1 are connected.
everything less than i MUST be it's own leader, and everything else must be a follower

just use a deque of leaders

