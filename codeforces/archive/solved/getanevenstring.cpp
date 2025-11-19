#include <bits/stdc++.h>
using namespace std; 

void solve(){
    string s; cin >> s;
    int len = (int)s.size();

    vector<int> alph(26, -1);
    int pairs=0, p=-1;
    for(int i=0; i<len; i++){
        if (alph[s[i]-'a'] != -1 and p < alph[s[i]-'a']){
            p = i;
            pairs++;
        }
        alph[s[i]-'a'] = i;
    }
    cout << len - 2*pairs << endl;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while(t--){
        solve();
    }
}
