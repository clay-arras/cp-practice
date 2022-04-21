#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;

    int cnt=0;
    for (char a : s){
        if (a == c) cnt++;
    }
    if (cnt == n){
        cout << 0 << endl;
        return;
    }

    for (int i=n/2; i<n; i++){
        if (s[i] == c){
            cout << 1 << endl;
            cout << i+1 << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << n-1 << " " << n << endl;
}



int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}
