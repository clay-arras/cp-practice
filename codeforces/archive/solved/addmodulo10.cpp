#include <bits/stdc++.h>
using namespace std;

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

    bool tens = false;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
        if (t % 10 == 5 or t % 10 == 0)
            tens = true;
    }

    int max = -1;
    if (tens){
       for (int i=0; i<n; i++){
           int t = a[i];
           if (max != -1){
               if (t != max and t+5 != max){
                   cout << "NO\n";
                   return;
               }
           }
           if ((t % 10 == 0 or t % 10 == 5) and max == -1){
               if (i != 0){
                   cout << "NO\n";
                   return;
               }else
                   max = t + (t % 10 == 5 ? 5 : 0);
           }
       }
    }
    if (max != -1){
        cout << "YES\n";
        return;
    }

    for (int i=0; i<n; i++){
        if (a[i] % 2 == 1){
            a[i] += a[i] % 10;
        }
        a[i] %= 20;
    }
    sort(a.begin(), a.end());

    priority_queue<int> dq;
    for (int i=0; i<n; i++)
        dq.push(a[i]);

    for (int i=0; i<2*n; i++){
        int t; t = dq.top();
        dq.pop();
        while(true){
            t += t%10;
            if (t >= 20){
               t -= 20;
               break;
            }
        }
        dq.push(t);
    }

    int f, l;
    for (int i=0; i<n; i++){
        if (i == 0)
            f = dq.top();
        if (i == n-1)
            l = dq.top();
        dq.pop();
    }
    cout << (f == l ? "YES" : "NO" ) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
