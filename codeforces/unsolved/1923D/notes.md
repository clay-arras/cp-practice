## form: rolling prefix from center trick

lets say we have an array A
- assume that for each i, we need a to query a prefix sum ENDING at i.
- more concretely, for any j in [0, i-1], we need to search on sum(A[j:i]) in
  O(N) time

to do this, we can have a hashmap, and a variable called `roll`
the logic is similar to the following:

> roll += A[i];
> ans += pref.query(x - roll);
> pref[A[i] - roll]++;

essentially, we update the rolling sum, and maintain a prefix that is offset by
the rolling sum


---

problem: there's a limit because of "same values". we can't just find the
lastTrue: we also need to decrement if there's a streak of "same values", until
we find one nonsame value.

lets construct an array lastDiff[i], where for each i it gives the last index
of the element thats different from A[i]

[1, 3, 3, 4]

its a dp. 
if (A[i] == A[i-1]) then its dp[i-1]
else its i-1
