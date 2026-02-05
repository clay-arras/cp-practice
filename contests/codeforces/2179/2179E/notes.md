## observation 1:
we don't care x or y if we are less than it, because we can always pad at the end
however, we DO care if we go OVER x and y. this constitutes an invalid case

for each p, we want to allocate the smallest number of voters s.t. ai + bi >=
pi. therefore, we want it s.t. 

if pi is even, then
ai = pi/2 + 1;
bi = pi/2 - 1;

if pi is odd, then
ai = ceil(pi/2)
bi = floor(pi/2)



## edge case 1:
you can always pad, EXCEPT in cases where s is all 1s or all 0s. in such a
case, you must check if all 0s, then X >= Y

generalization: the amount you pad X 

x = 24, y = 20
<!-- padding: 17 20 -->
padding: 18 20

2 0
2 0
2 0

2 0
2 0
20 20

if y is greater: NO
if y is equal: NO

so y must be less, but how less? 
if padding are equal: YES



## reset
assume that X has to win across the board (i.e., s is all zeros)
we want to figure out the rule X ? Y s.t. both can work.

assume we allocate the maximum we can for each Y (a - 1)
then we have min for X, and max for Y. we assert that X - xsum >= Y - yleft

xsum is the MINIMUM we need to allocate for X to still win
yleft is the MAXIMUM we can allocate for Y to still lose



4 3
5 4
7 6
2 1

x = 20, y = 16
xsum = 18
yleft = 14

x needs 2
y needs 2
