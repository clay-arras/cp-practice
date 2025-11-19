/*
Problem: find the greatest set bit among a range of numbers. 
Algoritm: precompute with a prefix array all of the values, and then answer the question. Large constant value loops are actually not as slow as I thought, so the solution is fast enough to pass.
Implementation: (1<<i)&j to check if they shared the same bit. Actually genius, I wouldn't have thought of that.

1615B
*/
#include <bits/stdc++.h>
using namespace std; 

using ll = long long;

int a[20][200005];
void solve(){
    int l, r; cin >> l >> r;

    int ans=2e5;
    for (int j=0; j<20; j++){
        ans = min(ans, r-l+1 - (a[j][r]-a[j][l-1]));
    } 
    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);

    for (int i=0; i<20; i++){
        for (int j=1; j<=2e5; j++){ 
            a[i][j] = a[i][j-1];
            if ((1<<i)&j) a[i][j]++;
        }
    }

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
