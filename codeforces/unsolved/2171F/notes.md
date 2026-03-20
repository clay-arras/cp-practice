<!-- keep track of the largest number BEFORE this that still hasn't been connected -->
<!-- yet. -->

<!-- if that number can be covered, then set back to -1. -->
<!-- if the cover number is not -1 at the end of the loop, then construction is impossible -->

<!-- we can just store it in a deque. if its the biggest then its first, otherwise insert it at the end. -->
<!-- check if the deque is empty at the end. -->



<!-- new idea: --> 

<!-- disjoint set union -->
<!-- have a list of LEADERS in a set somehow -->
<!-- keep track of BEFORE LEADERS and AFTER LEADERS. -->
<!-- every move, you want to merge with either one before leader or after leader -->



intuitively, you want to connect with the BEST so far.
- it's ALWAYS good to make a connection to a BIG value. (strictly reduces the
  number of connected components by one)
- however, you need a way to make FORWARD connections as well.

- which is why we need a DSU: we can't guarantee we're always forming a needed
  connection. we need a way to test different connections


define a connected component J as all the different forward connections i can
make. then i needs some way to break out, which greedily means you can just
choose the smallest element.

so for each number, you connect it to the prefix min and suffix max
