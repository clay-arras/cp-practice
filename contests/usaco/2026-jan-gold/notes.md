

# b
theorem: its always good to merge the smallest elements first
then the steps are the following: we need to first find the minimum milk cost
(which is deterministic and can be calculated), THEN we need to somehow DP the swapping order

think about how swapping changes which merges can happen!

define Ai as the ith minimum element
so the A0 has to be next to the A1th minimum element. then A2 has to be next to them
so the shape of the optimal merge array is the following: 
> A4 A2 A1 A0 A3

## edge cases:
when the numbers aren't distinct



