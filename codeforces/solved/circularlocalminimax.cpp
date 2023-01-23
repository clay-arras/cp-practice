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
    int n; cin >> n;

    vector<int> a;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    if (n % 2 == 1){
        cout << "NO\n";
        return;
    }

    sort(a.begin(), a.end());
    vector<int> b(a.begin(), a.begin() + n/2);
    vector<int> c(a.begin() + n/2, a.end());

    int bad = false;
    int half = n/2;
    for (int i=0; i<half; i++){
        if (b[i] >= c[i % half] or b[i] >= c[(i - 1 + half) % half]){
            bad = true;
        }
    }
    if (bad == true){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i=0; i<n/2; i++){
        cout << a[i] << " ";
        cout << a[i+n/2] << " ";
    }
    cout << "\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
