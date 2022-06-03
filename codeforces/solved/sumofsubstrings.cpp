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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int count = 0;
    int f = n, l = -1;
    for (int i=0; i<n; i++){
        if (s[i] == '1'){
            f = min(i, f);
            l = max(i, l);
            count++;
        }
    }

    int ans = count * 11;
    int fdist = f, ldist = n - 1 - l;

    if (count > 0 and k - ldist >= 0 and l != -1){
        ans -= 10;
        k -= ldist;
        count--;
    }
    if (count > 0 and k - fdist >= 0 and f != n){
        ans -= 1;
        k -= fdist;
        count--;
    }
    /* debug(fdist, ldist); */
    /* debug(s, f, l); */
    cout << ans << endl;

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
