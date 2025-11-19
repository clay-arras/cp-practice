#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MXP = 32;
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

Sieve<MXP> p;
void solve() {
    int N; cin >> N;

    vector<int> A(N);
    for (int& t : A)
        cin >> t;

    map<int, int> m;
    for (int prime : p.primes)
        m[prime] = -1;

    int colors = 0;
    vector<int> ans(N, 0);
    for (int i=0; i<N; i++) {
        for (int prime : p.primes) {
            if (A[i] % prime == 0) {
                if (m[prime] == -1) {
                    colors++;
                    m[prime] = colors;
                }
                ans[i] = m[prime];
                break;
            }
        }
    }
    cout << colors << endl;
    for (int i=0; i<N; i++)
        cout << ans[i] << " ";
    cout << endl;
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



*/
