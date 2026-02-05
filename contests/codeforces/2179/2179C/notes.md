
## observation 1: 
you can always get a number to a certain modulo P by setting x equal to A[i]-p
this works because its always good to set the modulo to as high a number as possible


## approaches:
- binary search over k
<!-- - binary search over Q, the number we want to set everyone to -->
<!-- - now given k and Q, we can check the array -->

<!-- simplification: given an array  -->

## observation 2:
we can always set a number to zero if k == A[i]
<!-- additionally, we can sort an array; it NEVER makes sense to set k between A[0] and A[1] -->

case 1: k = A[0], then we can set everything equal to zero
case 2: k is between A[0] and A[1]. we want A[1] - k = A[0]

