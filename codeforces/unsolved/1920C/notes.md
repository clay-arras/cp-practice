# observation 1: 
lemma: if p is a divisor of n, and there exists an m s.t. the subarrays are
equal (aka p will get a point), than for any other divisor q of n s.t. q p is a
divisor of q, q will get a point

conclusion: therefore, we only have to check the prime numbers, which is a
constant number

# observation 2: 
instead of checking remainders, we can get the difference of all numbers being
compared to each other (i.e. i, i+p, i+2p) so that all we need is to find a
number s.t. it divides all of the differences
we can do this simply by using gcd across everything



# algorithm:
- we can use sieve to get the prime numbers easily
- we loop through all prime divisors of N less than sqrtN
- for each prime divisor, we push back every DIFFERENCE between them
- finally, we go through the gcd of the difference list



## NOTE:

