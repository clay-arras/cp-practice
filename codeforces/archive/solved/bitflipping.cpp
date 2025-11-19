#include <bits/stdc++.h>
using namespace std;

string fb(int n, string s){
    string ss = "";
    for (int i=0; i<n; i++){
        ss += (!(s[i]-'0')) + '0';
    }
    return ss;
}
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> ans(n, 0);
    int parity = k%2;

    for (int i=0; i<n and k > 0; i++){
        if (s[i]-'0' == parity){
            ans[i]++;
            k--;
        }
    }

    ans[n-1] += k;
    for (int i=0; i<n; i++){
        int bit = s[i]-'0';
        if (ans[i]%2){ cout << !(parity^bit);
        }else{ cout << (parity^bit); }
    }
    cout << endl;

    for (int i : ans) cout << i << " ";
    cout << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}
