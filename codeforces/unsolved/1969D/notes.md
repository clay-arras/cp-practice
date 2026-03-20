
if the K constraint didn't exist, then Alice would just buy every item in which
(B[i] - A[i]) > 0, because she can always sell her wares.

given the K constraint, lets assume Alice employs the same strategy. in this
case, Bob will now choose the K elements Alice buys with the largest value by
this key: (B[i] - A[i]) + A[i] == B[i], which reduces her total sum

<!-- bet its dp over a sorted range, where we process the smallest B[i]s to the -->
<!-- largest (similarly sorted A[i]), and we choose K values to "sacrifice". -->
