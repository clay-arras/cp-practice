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
void swap(int i, int j, vector<int> &a){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void solve(){
    int n; cin >> n;

    vector<int> p, k;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        p.push_back(t);
        k.push_back(i+1);
    }
    if (n == 1){
        cout << -1 << endl;
        return;
    }

    /* vector<bool> bad(n, false); */
    for (int i=0; i<n-1; i++){
        if (p[i] == k[i]){
            /* bad[i] = true; */
            swap(i, i+1, k);
        }
    }

    if (p[n-1] == k[n-1])
        swap(n-2, n-1, k);

    for (int t : k)
        cout << t << " ";

    cout << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
