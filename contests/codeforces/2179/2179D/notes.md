<!-- ## observation 1:  -->
<!-- we want the biggest bits FIRST -->
<!-- the first 2^N - 2^N-1 bits should have the Nth bit set, then the  -->


## observation 2
we want the HIGHEST number of bits first, i.e. 2^N - 1 ALWAYS
the second bit is the smallest number...

ok. lets group numbers by the number of bits they have, and then sort it.
then we can just vector over it.


## lemma 1:
the ordering is just

11111, 01111, 00111, 00011, 00001
the rest are just sorted


## lemma 2: 
the previous ordering was incorrect

1111

0111

0011
1011

0001
0101
1001
1101

...rest

keep the set logic.
we need a way to 
