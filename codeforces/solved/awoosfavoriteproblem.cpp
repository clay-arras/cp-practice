#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;

    vector<int> sv, tv;
    for (int i=0; i<n; i++){
        if (s[i] != 'b')
            sv.push_back(s[i]);
    }
    for (int i=0; i<n; i++){
        if (t[i] != 'b')
            tv.push_back(t[i]);
    }
    bool c1 = (sv == tv);
    if (!c1){
        cout << "NO\n";
        return;
    }

    vector<int> sc, sa, tc, ta;
    for (int i=0; i<n; i++)
        if (s[i] == 'c')
            sc.push_back(i);

    for (int i=0; i<n; i++)
        if (t[i] == 'c')
            tc.push_back(i);

    for (int i=0; i<n; i++)
        if (s[i] == 'a')
            sa.push_back(i);

    for (int i=0; i<n; i++)
        if (t[i] == 'a')
            ta.push_back(i);

    bool c2 = true;

    for (int i=0; i<(int)sc.size(); i++){
        if (sc[i] >= tc[i]){
            continue;
        }
        c2 = false;
    }
    for (int i=0; i<(int)sa.size(); i++){
        if (sa[i] <= ta[i]){
            continue;
        }
        c2 = false;
    }

    if (c1 and c2)
        cout << "YES\n";
    else
        cout << "NO\n";

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
