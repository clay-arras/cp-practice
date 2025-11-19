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
    vector<int> p;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        p.push_back(t);
    }

    multiset<pair<int, int> > ac;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (p[i] < p[j]){
                ac.insert(make_pair(i, j));
            }
        }
    }

    multiset<pair<int, int> > bd;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (p[i] > p[j]){
                bd.insert(make_pair(i, j));
            }
        }
    }

    int ans = 0;
    for (auto u : ac){
        auto it = bd.lower_bound(u);
        for (auto itt = it; itt != bd.end(); ++itt){
            auto v = *itt;
            if (u.first < v.first and v.first < u.second and u.second < v.second){
                ans++;
            }
        }
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
