#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

const int MX = 3005;

string xoring(string a, string b, int n){
    string ans = "";

    for (int i=0; i<n; i++){
        if (a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    return ans;
}

void solve(){
    int n, x, y; cin >> n >> x >> y;
    string s1, s2; cin >> s1 >> s2;
    string s3 = xoring(s1, s2, n);

    vector<int> a;
    for (int i=0; i<n; i++){
        if (s3[i]-'0'){
            a.push_back(MX-i);
        }
    }

    int diff = (int)a.size();
    if (diff % 2){
        cout << -1 << endl;
    }else if (diff == 2){
        if (abs(a[0]-a[1]) == 1){
            cout << min(x*1LL, 2LL*y) << endl;
        }else{
            cout << diff*1LL/2 * y << endl;
        }
    }else{
        cout << diff*1LL/2 * y << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
