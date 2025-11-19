#include <bits/stdc++.h>
using namespace std; 

struct cow{int c=0, o=0, w=0;};
char letters[3] = {'C', 'O', 'W'};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */
    string s; cin >> s;

    int len = (int)s.size();
    vector<cow> pref(len + 1);
    for(int i=0; i<len+1; i++){
        pref[i+1] = pref[i];
        
        if (s[i] == letters[0]) pref[i+1].c++;
        else if (s[i] == letters[1]) pref[i+1].o++;
        else if (s[i] == letters[2]) pref[i+1].w++;
    }

    int Q; cin >> Q;
    while(Q--){
        int l, r; cin >> l >> r;
        int c = (pref[r].c - pref[l-1].c)%2;
        int o = (pref[r].o - pref[l-1].o)%2;
        int w = (pref[r].w - pref[l-1].w)%2;

        if (c and !o and !w) cout << "Y";
        else if (!c and o and w) cout << "Y";
        else cout << "N";
    }
    cout << endl;
}

