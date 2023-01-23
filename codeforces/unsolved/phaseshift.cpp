#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

void solve(){
    int n; cin >> n;
    string t; cin >> t;
    string s = "";

    vector<int> seen(26, 0), used(26, 0);
    map<char, char> ch;
    for (int i=0; i<n; i++){
        char on = t[i];

        if (seen[on-'a'] == 0){
            seen[on-'a'] = 1;

            int j=0;
            for (; j<26; j++){
                if (used[j] == 0){
                    used[j] = 1;
                    if (seen != used or count(seen.begin(), seen.end(), 1) == 26){
                        break;
                    }
                    used[j] = 0;
                }
            }
            ch[on] = (char)(j+'a');
        }

        s += ch[on];
    }
    /* for (auto &[k, i] : ch){ */
    /*     cout << k << " " << i << endl; */
    /* } */
    /* debug(seen); */
    /* debug(used); */
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}

// bcdefghijklmnopqrstuvwxya{
// bcdefghijklmnopqrstuvwxyaz
//
// bcdefghijklmnopqrstuvwxyz{
// bcdefghijklmnopqrstuvwxyza
