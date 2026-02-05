observation: can't you ALWAYS do this in 3 operations? 
remove all Cs, remove all Os, remove all Ws
the case where optimal is one is just a check in O(N)

if N is odd, then false trivially

---


<!-- lemma: for the K = 2 case, the ONLY case where this happens will need you to -->
<!-- remove WHOLE words, NOT SPLITS -->
<!-- ABCBABBC -->
<!-- remove BBs, then remove ABCABC -->
<!-- can we come up with a counterexample where lemma 1 isn't true? -->



lemma: if there are only TWO types of COW strings, then we can ALWAYS do it in K = 2
is there an example where we have three strings but K = 2? YES

if there are THREE types of COW strings, then what are the cases where we can
remove it in two operations?


--- 
WCO WCO 
same as COW

lemma: any two consecutive characters can match ANY characters and itself
only works with consecutive strings S


---

WHAT WE'RE LOOKING FOR: a deterministic way to determine if there's a K = 2
case for a given string, and if so, find it


--- 
what if there's a way to transform an operation into a shift?



WCO COW WCO WCO
OWC COW WCO WCO OWC COW  // 3 strings, ans = 2
OWC WCO COW OWC COW WCO  // 3 strings, ans = 2
WCO OWC COW WCO WCO OWC  // 3 strings, ans = 2


what if its some way to transform? like if we have even counts of some number
of variables, then we can do something?
ORDER MATTERS!!


claim: the only patterns you need to remove are FULL WORDS???


CO, OW, WC


all the 1s have to form a k=1, and all the 2s have to form a k=1
HOWEVER, what if there's a parity/constructive way we can do this?


