#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*


Have some sort of set
Store the converse, when we get an add query we can just remove

Store an array of all the numbers
Store an array of all possible K's
Originally all mex[k] = k
When we add an element to the array, we have to update mex[x]


6
+ 100
? 100
+ 200
? 100
+ 50
? 50

 50 100 150 200
 50 100 150 200

 +100
 50 100 150 200
 50 100 150 200


Keep every number




Let's look at a stupid solution and try to improve it.
In a stupid solution, we can simply add to the set, and when answering a query, iterate over the numbers 0,𝑘,2𝑘,3𝑘,… and so on until we find the answer. This solution will take a long time if the answer is 𝑐⋅𝑘 , where 𝑐 is large.
We will improve the solution. If a request comes to us for the first time for a given 𝑘 , then we calculate the answer for it greedily and remember it. In the future, we will no longer check with 0 whether there is a number in the set, but with the previous answer.



 Sieve of Eratosthenes
 Only visit primes => log(N)
 Too slow to calculate all the primes

*/
