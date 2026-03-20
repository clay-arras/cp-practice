[0 0 0 0] -> 5
[0] -> 2

[0, 1] -> 4
[0, 0, 1] -> 6
[0, 0, 0, 1] -> 8 (n + 1 + 3)

its (num_zeros + 1) * (num_ones + 1)... etc
algorithm: factorize into components, then for each factor term, we just add X numbers until its filled up

---
