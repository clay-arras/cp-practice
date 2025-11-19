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

   vector<int> a;
   int cnt = 1;
   for (int i=1; i<n; i++){
        if (s[i-1] == s[i]){ cnt++;
        }else{
            a.push_back(cnt);
            cnt = 1;
        }
   }
   a.push_back(cnt);

   vector<int> b;
   for (int i=0, len=(int)a.size(); i<len; i++){
        if (a[i]%2 == 1){
            b.push_back(i);
        }
   }

   int ans = 0;
   for (int i=0, len=(int)b.size(); i<len; i+=2){
       ans += b[i+1]-b[i];
   }
   cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
