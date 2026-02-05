
simp #1: lets assume that all the coach's ranges are distinct
then each segment is independent, so we MULTIPLY

to calculate the cost of each segment, we do the following: 
- coach is off: 1
- coach is on: 2^j, where j is the number of campers in that range

so its: prod (2^j + 1) - 1
