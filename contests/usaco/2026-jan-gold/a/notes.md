lets view the COW and BEST FRIEND structure as a disjoint set union, since they
all have exactly one pointer.

we can process the cow parties backwards, noting the following properties: if a
cow starts a party, they will ALWAYS have a party for the rest of the problem

therefore, we can process each thing sequentially. at each step, exactly one of
two things will happen (given we process backwards)
- a cow j will switch parties (we subtract the size of d.size(j) and add it to the new party)
- a cow j will stop partying (we merge cow j with its best friend. if its best
  friend is already in the cc, then we discard that group)


---
- an array detailing which party each cow is in (for leaders)
- a way to find out when cows stop partying (for leaders)
- a way to find cycles at the start ... when we're merging all the guys that
  don't have a party, we check cycles during that time

---


<!-- algos: -->
<!-- - dp on trees  -->
<!-- - dsu, where if we check this guy and its not right, then we merge it with its parent -->

<!-- BECAUSE of the time constaint, we need to somehow lazily update things -->

## edge cases:
can a cow be a best friend with themselves? if so, how do we check?
can cow A be cow B's best friend, and vice versa (loops?), then the only way to
break it is if ONE of the loop people have a party?

what if we have a loop and TWO of the loops have a party?

WHEN A COW HAS A PARTY, they ALWAYS HAVE A PARTY UNTIL THE END OF THE PROBLEM

in this way, we can break all cycles. if there IS a cycle, then all cows in the
cycle will NEVER have a party to go to, UNTIL one of the cows in the cycle
decides to leader to itself

WE HAVE TO GO BACKWARDS!!!! we have to process the parties offline PATTERN FOR DSU

---


if a cow doesn't have a party anymore, (when going backwards), you merge them
with their best friend

on each step exactly one of two things will happen:
a) a cow will switch parties (subtract and add the party size of that DSU cc)
b) a cow will stop partying (then merge, and add the size before merging to the party type of leader)


---

how do we deal with loops

sometimes, situation B will result in a loop. we need a way to calculate that,
because once it happens, THAT GROUP IS INACTIVE FOREVER

IF THERE IN THE SAME CC THEN WE REMOVE THAT CC FOREVER.

