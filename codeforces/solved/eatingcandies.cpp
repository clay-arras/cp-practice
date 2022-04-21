#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    int c=0;
    int l=0, r=n-1;

    int lsum=a[l], rsum=a[r];
    while (l < r){
        if (lsum == rsum){
            c = max(c, l + 1 + n - r);
            l++, r--;
            lsum += a[l], rsum += a[r];
        }else if (lsum > rsum){
            r--;
            rsum += a[r];
        }else if (rsum > lsum){
            l++;
            lsum += a[l];
        }
    }
    cout << c << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

