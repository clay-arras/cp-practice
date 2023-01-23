#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

vector<int> arr[10];
void solve(){
    string s; cin >> s;
    int n = (int)s.size();

    for (int i=0; i<n; i++){
        arr[s[i]-'0'].push_back(i);
    }

    int curr = -1;
    string s1, s2;

    for (int i=0; i<10; i++){
        for (int j : arr[i]){
            if (j >= curr){
                s1 += to_string(i);
                curr = j;
            }else{
                s2 += to_string(min(i+1, 9));
            }
        }
    }
    string s3 = s1+s2;
    sort(s3.begin(), s3.end());
    cout << s3 << endl;

    vector<int> tmp;
    fill(arr, arr+10, tmp);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
