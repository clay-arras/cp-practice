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
    int n, m, k; cin >> n >> m >> k;
    string a, b; cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    debug(a, b);

    string ans = "";
    int acount = 0, bcount = 0;
    while((int)a.size() and (int)b.size()){
        if (bcount == k){
            ans += a[0];
            a = a.substr(1, (int)a.size() - 1);
            acount++, bcount = 0;
        }else if (acount == k){
            ans += b[0];
            b = b.substr(1, (int)b.size() - 1);
            bcount++, acount = 0;
        }else if (a < b){
            ans += a[0];
            a = a.substr(1, (int)a.size() - 1);
            acount++, bcount = 0;
        }else if (a > b){
            ans += b[0];
            b = b.substr(1, (int)b.size() - 1);
            bcount++, acount = 0;
        }
    }
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
