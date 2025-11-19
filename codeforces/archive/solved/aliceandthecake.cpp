#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
/* #define cerr if(0) cerr */
#include <debug.h>
#else
#define debug(...)
#endif

void solve(){
    int n; cin >> n;
    multiset<int> a;

    long long sum = 0;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.insert(t);
        sum += t;
    }
    stack<long long> c;
    c.push(sum);

    while (!a.empty()){
        if (c.empty()){
            cout << "NO" << endl;
            return;
        }

        long long t = c.top();
        auto it = a.find(t);
        if (it != a.end()){
            a.erase(it);
            c.pop();
        }else if (t > 1){
            c.pop();
            c.push(ceil(t*1.0/2));
            c.push(floor(t*1.0/2));
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

