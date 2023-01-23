#include <bits/stdc++.h>
using namespace std; 

string s, t;
void solve(){
    string q; cin >> q;
    set<char> let;
    for (char c : q) let.insert(c);

    int sp=0, tp=0;
    int slen = (int)s.size(), tlen = (int)t.size();
    while(sp < slen and tp < tlen){
        while (let.count(s[sp]) == 0 and sp < slen) sp++;
        while (let.count(t[tp]) == 0 and tp < tlen) tp++;
        if (s[sp] != t[tp]){
            cout << "N";
            return;
        }
        sp++;
        tp++;
    }
    cout << "Y";
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);
    
    cin >> s >> t;
    int Q; cin >> Q;
    while(Q--){
        solve();  
    }
    cout << endl;
}
