#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif
/* vector<int> ones{2 }; */
int threes[] = {2, 1, 3};
long long twos[] = {(1LL<<30) + (1LL<<28), (1LL<<30) + (1LL<<29) + 1, (1LL<<28), (1LL<<29), 0, 1};
long long ones[] = {1, (1LL<<30) + (1LL<<28), (1LL<<30) + (1LL<<29) + 1, (1LL<<28), (1LL<<29)};
void solve(){
    int n; cin >> n;

    vector<int> a[2];
    int t = n;
    if (n%4 == 0){

    }else if (n%4 == 1){
        t -= 5;
    }else if (n%4 == 2){
        t -= 6;
    }else if (n%4 == 3){
        t -= 3;
    }

    int p = 0;
    for (int i=4; i<t+4; i+=2){
        a[p].push_back(i);
        a[p].push_back(i+1);
        p ^= 1;
    }

    for (int i=0; i<t/2; i++){
        cout << a[0][i] << " " << a[1][i] << " ";
    }

    if (n%4 == 0){
    }else if (n%4 == 1){
        for (long long i : ones){
            cout << i << " ";
        }
    }else if (n%4 == 2){
        for (long long i : twos){
            cout << i << " ";
        }
    }else if (n%4 == 3){
        for (long long i : threes){
            cout << i << " ";
        }
    }

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
