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

    vector<int> p;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        p.push_back(t);
    }

    int index=0, min_val=0;
    for (int i=0; i<k; i++){
        min_val += p[i];
    }

    int sum = min_val;
    for (int i=0; i<n-k; i++){
        if (sum < min_val){
            index = i;
            min_val = sum;
        }
        sum += p[i+k] - p[i];
    }

    if (sum < min_val){
        index = n-k;
        min_val = sum;
    }

    cout << index + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t=1;
   	while(t--){
   		solve();
   	}
}
