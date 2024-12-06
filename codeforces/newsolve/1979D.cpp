#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, K; cin >> N >> K;
    string s; cin >> s;

    int ok = true;

    int i;
    for (i=N-1; i>N-K && i>0; i--) {
        if (s[i] != s[i-1]) {
            i--;
            break;
        }
    }
    i = max(0, i-K);
    while (i > 0 && s[i-1] != s[i+K-1]) i--;
    if (s[i-1] != s[i]) {
        while (s[i+1] == s[i]) i++;
        i = min(N-1, i+1);
    }


    string s1 = s.substr(0, i);
    string s2 = s.substr(i);
    reverse(s1.begin(), s1.end());

    string ns = s2 + s1;

    for (int j=1; j<K; j++) {
        ok &= (ns[j] == ns[j-1]);
    }

    for (int j=K; j<N; j++) {
        ok &= (ns[j] != ns[j-K]);
    }
    cout << (ok ? i : -1) << endl;
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

// check from back if its k-proper
// if its not then that's p
// finally check if last string is k-proper


// how to implement?


*/
