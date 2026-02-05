#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    vector<int> A(N);
    for (int i=0; i<N; i++)
        A[i] = s[i]-'0';
    
    long long res = 0, ans = 0;
    unordered_map<long long, long long> m;
    for (int i=N-1; i>=0; i--) {
        m[res]++;
        res += 1 - A[i];
        ans += m[res];
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
