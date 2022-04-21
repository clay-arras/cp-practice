#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;

    multiset<string> ss;
    set<string> sss;
    for (int i=0; i<n; i++){
        string s; cin >> s;
        ss.insert(s);
        sss.insert(s);
    }

    long long ans=0;
    map<string, int> a;
    for (string s : ss){
        string p = ".";
        p += s[1];

        string q = "";
        q += s[0];
        q += ".";

        a[p]++, a[q]++;
    }

    long long sub=0;
    for (string s : sss){
        int t = ss.count(s);
        sub += (t-1)*t/2;
    }


    for (auto const& [k, v] : a){
        ans += (v-1)*v/2;
    }
    cout << ans - 2*sub << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

