#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2e5+2;

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
Sieve<MX> sieve;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    unordered_map<int, int> m;
    auto is_valid = [&](int p) {
        vector<int> diffs;
        for (int off=0; off<p; off++) 
            for (int i=off; i<N-p; i+=p) 
                diffs.push_back(A[i] - A[i+p]);

        if ((int)diffs.size() == 0) 
            return true;
        
        int div = abs(diffs[0]);
        for (int i=1; i<(int)diffs.size(); i++)
            div = gcd(div, abs(diffs[i]));
        return (div != 1);
    };

    for (int p : sieve.primes) {
        if (p > sqrt(N)) 
            break;
        if (N % p != 0)
            continue;

        if (is_valid(p))
            m[p] = 1;
        if (is_valid(N/p))
            m[N/p] = 1;
    }
    if (is_valid(1)) m[1] = 1;
    if (is_valid(N)) m[N] = N;

    int ans = 0;
    auto incr_ans = [&](int i) {
        bool ok = false;
        for (int j=1; j<=sqrt(i); j++) 
            if (i % j == 0)
                ok |= m[j] || m[i/j];
        return ok;
    };

    for (int i=1; i<=sqrt(N); i++) { 
        if (N % i != 0)
            continue;
        ans += incr_ans(i);
        if (N/i != i) ans += incr_ans(N/i);

    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
