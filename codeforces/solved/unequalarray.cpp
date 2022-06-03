#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    bool c = false;
    int f = n-1, l = 0;
    for (int i=0; i<n-1; i++){
        if (a[i] == a[i+1]){
            f = min(i, f);
            l = max(i+1, l);
            c = true;
        }
    }
    if (!c or l-f == 1) cout << 0 << endl;
    else cout << max(1, l-f-2) << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}
