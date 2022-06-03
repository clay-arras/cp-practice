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
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    if (is_sorted(a.begin(), a.end())){
        cout << 0 << endl;;
        return;
    }else if (a[n-1] < a[n-2] or a[n-1] < 0){
        cout << -1 << endl;
        return;
    }else{
        cout << n-2 << endl;
        for (int i=0; i<n-2; i++){
            cout << i+1 << " " << n-1 << " " << n << endl;
        }
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
