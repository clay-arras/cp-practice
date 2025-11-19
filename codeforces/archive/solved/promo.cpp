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
    int n, q; cin >> n >> q;
    vector<long long> p;

    for (int i=0; i<n; i++){
        long long t; cin >> t;
        p.push_back(t);
    }
    sort(p.begin(), p.end());
    vector<long long> pref(n+1, 0LL);

    for (int i=0; i<n; i++){
        pref[i+1] = pref[i];
        pref[i+1] += 1LL * p[i];
    }

    vector<long long> ppref = pref;
    reverse(ppref.begin(), ppref.end());
    while(q--){
        int x, y; cin >> x >> y;
        cout << pref[n] - pref[n-x] + (ppref[x-y] - ppref[0]) << endl;
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t = 1;
   	while(t--){
   		solve();
   	}
}
