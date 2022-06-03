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
void solve2(){

}

void solve1(){
    int n, k; cin >> n >> k;
    map<int, int> m;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        m[--t]++;
    }
    m[1e9+5], m[-1];

    int kp = 0;
    bool good = false;
    pair<int, int> ans = make_pair(-1, -1), c = make_pair(0,0);
    for (const auto& [key, v] : m){
        if (v >= k){
            if (!good) {
                good = true;
                c.first = key;
                c.second = key;
            }else if (kp + 1 == k){
                c.second++;
            }
        }else{
            good = false;
            if (ans.second - ans.first <= c.second - c.first){
                ans.second = c.second;
                ans.first = c.first;
            }
            c.first = -1, c.second = -1;
        }
        kp = key;
    }
    if (ans.first == -1) cout << -1 << endl;
    else cout << ans.first+1 << " " << ans.second+1 << endl;
}

void solve(){
    int n, k; cin >> n >> k;
    map<int, int> m;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        m[--t]++;
    }
    m[1e9+5], m[-1];

    int kp = 0;
    bool good = false;
    pair<int, int> ans = make_pair(-1, -2), c = make_pair(-1, -2);
    for (const auto& [key, v] : m){
        debug(c, ans);
        if (kp + 1 == key and v >= k){
            if (!good){
                good = true;
                c.first = kp;
                c.second = kp;
            }else{
                c.second++;
            }
        }else{
            good = false;
            if (ans.second - ans.first <= c.second - c.first){
                ans.second = c.second;
                ans.first = c.first;
            }
            c.first = 0, c.second = 0;
        }
        kp = key;
    }
    if (ans.first == -1) cout << -1 << endl;
    else cout << ans.first+1 << " " << ans.second+1 << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve1();
   	}
}
