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

long long sp (vector<int> a){
    long long sum = 0, n = (int)a.size();
    sort(a.begin(), a.end());

    for (long long i=n-1; i>=0; i--)
        sum += i*1LL*a[i] - (n-1-i)*1LL*a[i];
    return sum;
}

void solve(){
    int n, m; cin >> n >> m;
    if (n == 1 and m == 1){
        cout << 0 << endl;
        return;
    }

    vector<vector<int> > x;
    vector<vector<int> > y;
    map<int, int> a; int k=1;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int t; cin >> t;
            if (a[t] == 0) a[t] = k++;

            while ((int)x.size() <= k){
                x.push_back(vector<int> ());
                y.push_back(vector<int> ());
            }

            x[a[t]].push_back(i);
            y[a[t]].push_back(j);
        }
    }

    long long ans = 0;
    for (int i=0; i<k+1; i++){
        ans += sp(x[i]);
        ans += sp(y[i]);
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
   	while(t--){
   		solve();
   	}
}
