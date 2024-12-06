#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template <int SZ>
struct Sieve {
	bitset<SZ> is_prime; vector<int> primes;
	Sieve() {
		is_prime.set();
        is_prime[0]=is_prime[1]=0;
		for (int i=4; i<SZ; i+=2) is_prime[i] = 0;
		for (int i=3; i*i<SZ; i+=2) {
            if (is_prime[i])
                for (int j=i*i; j<SZ; j+=i*2)
                    is_prime[j] = 0;
        }
        for (int i=0; i<SZ; i++) {
            if (is_prime[i])
                primes.push_back(i);
        }
	}
};

const int MX = (int)1e7+7;
void solve() {
    int n; cin >> n;

    Sieve<MX> S;
    /* cout << endl; */
    /* cout << n << endl; */
    while (n--) {
        int a, b; cin >> a >> b;
        int tmp = b-a;

    }

}

// gcd(a+k, y-x) = g
// then g|a+k and g|y-x
// a+k = gp
// y-x = gq
//
// find all prime divisors of y-x
// (a+k)p = (y-x)q

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

