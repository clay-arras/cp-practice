#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<int SZ, int MXBIT> struct Trie {
    int next[SZ][2], sz[SZ], num = 0;
    long long mxV = 1e18+9;
    Trie() { memset(next, 0, sizeof(next)); memset(sz, 0, sizeof(sz)); }
    void insert (long long x, int a = 1) {
        int curr = 0; sz[curr] += a;
        for (int i=MXBIT-1; i>=0; i--) {
            int t = (x>>i)&1;
            if (!next[curr][t])
                next[curr][t] = ++num;
            sz[curr = next[curr][t]] += a;
        }
    }
    long long maxXOR(long long x) {
        if (!sz[0]) return -mxV;
        int curr = 0;
        for (int i=MXBIT-1; i>=0; i--) {
            int t = ((x>>i)&1)^1;
            if (!next[curr][t] || !sz[next[curr][t]])
                t ^= 1;
            curr = next[curr][t];
            if (t) x ^= (1LL<<i);
        }
        return x;
    }
};

void solve() {
    int N; cin >> N;

    vector<int> A(N);
    for (int& t : A)
        cin >> t;


}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*

Values that differ by the least

Dense graphs MST
Trie
Radix sort

Prim


*/

