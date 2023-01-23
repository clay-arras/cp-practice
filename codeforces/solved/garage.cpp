#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif


const int MX = 1e9+9;
int cost(int m){
    return m - 3 - floor((m-3)*1.0/4);
}

int N;
void solve(){
    cin >> N;
    if (N == 1){
        cout << 3 << endl;
        return;
    }

    int x = -1;
    for (int b = MX; b >= 1; b /= 2) {
        while (cost(x+b) <= N) x += b;
    }

    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t = 1;
    /* int t; cin >> t; */
    while(t--){
        solve();
    }
}
