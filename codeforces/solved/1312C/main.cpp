#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

long long intLog(long long x, long long base) {
    long long result = 0;
    while (x >= base) {
        x /= base;
        result++;
    }
    return result;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int N, K; cin >> N >> K;
    vector<long long> a(N);
    for (auto& i : a)
        cin >> i;

    priority_queue<long long> m;
    for (auto i : a)
        m.push(i);

    for (long long mx = 55; mx >= 0; mx--) {
        long long bg = m.top(); m.pop();
        if (bg == 0)
            break;
        mx = min(mx, intLog(bg, K));
        m.push(bg - binpow(K, mx));
    }
    bool ok = true;
    while (!m.empty()) {
        ok &= (m.top() == 0);
        m.pop();
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
