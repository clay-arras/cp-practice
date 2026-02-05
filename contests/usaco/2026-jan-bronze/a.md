lemma 1: we always want to exchange chips of type B for chips of type A

## CORE LEMMA: the only two cases we need to check is if all the chips
are type A, or all the chips are type B

justification: we need GUARANTEED end up with at least fA chips
- case 1: if cA < cB (we exchange MORE B chips for less A chips), then
  the worst case scenario is if we all get B chips
- case 2: if cA > cB (we exchange LESS B chips for more A chips), then
  ---------------------------------------- A chips


## edge case: what if we recieve cB-1 chips of type B, k chips of type A
> cB = 5
> cA = 6
> A = 0
> B = 0
> fA = 12

minimum according to our algorithm is 12
however, what if we get 9 B chips and 3 A chips? then the greedy won't work

<!-- misc note: does this only apply to case 2??? ans: yes, because
otherwise it'll never be unoptimal to get more As.... NO -->



## final edge case:
we can also check an edge case where we do all Bs but 
    B === -1 (mod cB)
which is another unoptimal scenario
answer: assume B = cB-1, A = rest

final other edge case: 
the other side if (cA < cB) then we do MAX cB where B == -1 (mod cB)



number of Bs for the assertion to be fullfilled:
<!-- - if ((x + B) % cB == cB - 1) then we're good -->
<!-- - else ((x + B) // cB) * cB -->

we've already tested putting everything into B, so we need the -1 condition
- amt = ((x + B) // cB) * cB - 1
- x - (amt-B)


---

try every single possible x value and every single possible split
test on all trivial test cases
