<!-- lets try to find a path that MINIMIZES the MAXIMUM, and MAXIMIZES the MINIMUM -->
<!-- e.g. `min(max(dp[i][j], dp[i-1][j]), max(dp[i][j], dp[i][j-1]))` -->
<!-- ## CORE lemma: if we have the minimum and the maximum, we can take their -->
<!-- product to get the number of valid solutions -->

<!-- the question is how do we calculate the dp when you can go from side to side loop -->
<!-- process it every N, and process both at the same time -->

---
because it's only a down-right path, there are exactly N paths, which
corresponds to the N positions we have to go down in (every other operation
will go right)

- hence, we can create a prefix and a suffix for each row, and calculate the
  maximum L and minimum R that lets that path be traversed
- then, for each L, we can have a hashmap that stores the minimum R that makes
  the path valid

we then traverse the possible L values, from smallest to biggest, and somehow
count those intervals...

<!-- the question is, how do we effectively count the number of intervals in a nice -->
<!-- way? we can  -->
