
*constraints*: 
need to be O(N) or O(NlogN) solution

*observations*: 
- could be similar to Manacher's, dp over "palindromic" sequences
- assertion: different placements of these queries ALWAYS result in
  different final colorings. therefore, we can count the different ways
  to place instead of worrying about the final colorings.
- by string and dp definition, odd strings can't be colored EVER

*note*:
- you DON'T NEED to color EVERYTHING


## tentative solution

we process this similar to Manacher's algorithm. we have two pointers, L
and R. L should represent the MIDDLE of the subsequence, and R should
represent the RIGHTMOST subsequence. in other words, L should point to
the last red, and R should point to the last blue.

at the start of each loop, we increment R as long as it's mirrored
counterpart is blank or red. then, we need to increment L. we are cool
if L lands on red or blank, but we CANNOT let L land on blue. if this
happens, we continue incrementing until it isn't on blue.

refinement: we construct RMQs that allow us to check whether a certain
section contains red or blue. this way, we can increment L until the
construction is valid again, after we increment L at least once.

if R runs into a red, then we'd want to increase it until it's not on
red anymore? we'd want to RUN both pointers up until we come across the
next RB XB RX pair, and then continue the process.


---

everything before dp[i] is a VALID coloring: not necessarily that everything is colored
dp[i] definition: the number of ways to color the string up until i


we ALWAYS move the left pointer to the right every single timestep. 
we want the left pointer to always be a VALID pointer. i.e. the space it occupies is VALID.
we also want the right pointer to stop expanding when its invalid.

need a function that determines validity. 
- left zone occupies is [L-(R-L-1), L]
- right zone occupies is [L+1, R]

update dp[R] += dp[L-(R-L-1)]


MOVEMENT rules:
```cpp
dp = vector<int> (N, -1);
int L, R;
for (; L<N; ) {
    while (!is_valid(L-(R-L-1), L)) {
        L++;
        if (L == R) R++;
    }
    dp[R] += dp[L-(R-L-1) - 1]; // right BEFORE our partition
    while (L-((R+1)-L-1) - 1 >= 0 && is_valid_b(L+1, R+1)) {
        dp[R] += dp[L-(R-L-1) - 1];
        R++;
    }
    // process

    
    L++
    if (L == R) R++;
}
```

NOTE: what is the base case?
idea: invalid cases exist, only partition if VALID
note: if white, the sum up all the VALID points before this.

---



RB -> guaranteed center
BR -> guaranteed break
divide and conquer???

every lingering R and B needs to be part of a center.

assume the case with NO defined centers. here, we can for each center just
guess at each position and guess
XXRXX
XXRXXXB

assume the case with only one center. in that case, we can just greedily
expand. the whitespace at the edges can or cannot be filled
XXXRBXXX: 4 ways

--- 
HINT: we are starting with an O(N^2) dp
