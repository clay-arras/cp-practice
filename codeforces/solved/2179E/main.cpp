#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, X, Y; cin >> N >> X >> Y;
    string s; cin >> s;

    vector<int> P(N);
    for (int& i : P)
        cin >> i;
    
    long long sum = 0;
    for (int i : P)
        sum += i;

    if (sum > X*1LL + Y) {
        cout << "NO" << endl;
        return;
    }

    long long xmin=0, ymin=0;
    long long xmax=0, ymax=0;
    for (int i=0; i<N; i++) {
        long long wn = ceil((P[i]+1)*1.0/2);
        long long ls = wn - 1;
        
        if (s[i] == '0') {
            xmin += wn;
            ymax += ls;
        } else {
            xmax += ls;
            ymin += wn;
        }
    }

    cerr << xmin << " " << ymin << " " << xmax << " " << ymax << " " << endl;
    sort(s.begin(), s.end());
    if (s[0] != s[N-1]) {
        cout << (xmin <= X && ymin <= Y ? "YES" : "NO") << endl;
        return;
    }

    if (s[0] == '0') {
        cout << (xmin <= X && (ymax + (X - xmin)) >= Y ? "YES" : "NO") << endl;
    } else {
        cout << (ymin <= Y && (xmax + (Y - ymin)) >= X ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
