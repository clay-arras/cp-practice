#include <bits/stdc++.h>
using namespace std;

string k[] = {"((", "))", "()"};
void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int ops=0;
    int l, r=0;
    for (l=0; l<n-1;){
        string s0 = s.substr(l, 2);
        if (s0 == k[0] or s0 == k[1] or s0 == k[2]){
            l += 2;
            ops++;
            continue;
        }
        r=l+1;
        while (r<n and s[r] != ')') r++;
        if (r == n) break;

        l = r+1;
        ops++;
    }
    cout << ops << " " << n - l << endl;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while(t--){
        solve();
    }
}
