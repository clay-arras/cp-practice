
this problem can be broken up into two steps:

a) we calculate an array L and array R, which represent how many
timesteps until this number i runs into a number less than it, and how
many timesteps until a number less than i runs into i.

i.e. if the array was [3, 8, 6, 4, 8, 3, 8, 1]
then              L = [1, 1, 2, 3, 1, 6, 1, N]
then              R = [5, 1, 1, 2, 1, 2, 1, N]
etc.

R: how many we can go until we can't override anymore
L: how many we can go until we start getting overridden

b) using this array, we construct PYRAMIDS across the answer array. the
answer array will be constructed as a 2nd-order difference array
(reconstructed will be the answer), and the pyramid grows starting from
timestep zero, stops growing at timestep Li, and shrinks starting at
timestep Ri (similar to trapezoids)

timesteps:
   1        3  4  3 6

1: 11       33 44 3 6 = 25
2: 111      33 44 3   = 20
3: 1111     33 4  3   = 17
4: 11111    33    3   = 14
5: 111111   33        = 12
6: 1111111  3         = 10
7: 11111111           = 8

8: 11111111

note: assume == does not overrides
- we can draw a diagonal trapezoid that increases from 0 to Ri timesteps
- then after Li timesteps draw the same trapezoid shifted downward
