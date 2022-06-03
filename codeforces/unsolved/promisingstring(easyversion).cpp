#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> ppref(n+1, 0);
    vector<int> mpref(n+1, 0);

    bool subt = false;
    for (int i=1; i<n+1; i++){
        ppref[i+1] = ppref[i];
        mpref[i+1] = mpref[i];
        if (s[i] == '+') {
            subt = false;
            ppref[i+1]++;
        }
        if (subt and s[i] == '-'){
            mpref[i+1]++;
            subt = false;
        }else if(s[i] == '-'){
            subt = true;
        }
    }

    int ans = 0;
    for (int i=1; i<n+1; i++){
        for (int j=i+1; j<n+1; j++){
            int np = ppref[j] - ppref[i-1];
            int nm = mpref[j] - mpref[i-1];

            int len = j - (i-1);
            int nn = len - np;
            if ((nn - np) % 3 == 0 and (nn-np)/3 <= nm){
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
// 2
// 4
// 2
// 7
// 4
