#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = (int)s.size();

    int a = 0, b = 0;
    for (int i=0; i<n; i++){
        if (s[i] == 'A') a++;
        else if (s[i] == 'B') b++;

        if (a < b){
            cout << "NO" << endl;
            return;
        }
    }
    if (a >= b and b > 0 and s[0] != 'B' and s[n-1] != 'A'){ cout << "YES" << endl;
    }else{ cout << "NO" << endl; }
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}
