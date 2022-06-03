#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    // array with all the shifts
    int v = s[0] - 'a';
    debug(v, s);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
// ideas:
// count the distance that it will take
// count the distance that the first one is from a
    // v = s[0] - 'a'
// then we need to count how many other ones are from the first one
// and prioritize them
