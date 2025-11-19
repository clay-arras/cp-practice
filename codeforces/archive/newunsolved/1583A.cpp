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

Sieve<20005> p;
void solve() {
    int N; cin >> N;

    long long sum = 0, odd = -1;
    vector<int> A(N);
    for (int& t : A) {
        cin >> t;
        sum += t;
        if (t % 2)
            odd = t;
    }

    if (p.is_prime[sum] == 0) {
        cout << N << endl;
        for (int i=0; i<N; i++)
            cout << i+1 << " ";
        cout << endl;

    } else {
        cout << N-1 << endl;
        for (int i=0; i<N; i++)
            if (A[i] != odd)
                cout << i+1 << " ";
        cout << endl;
    }
}
/* 2 3 6  == 11 */

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
*/
