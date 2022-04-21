#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n]; for (int& t : a) cin >> t;

    // a number to track
    // while the numbers are n+1 increment
    // when the next number isn't or is n then we start a new one
    // ans to increment which one we are on
    int ans=0;
    int N=0;
    bool Np1=false;
    for (int i=1; i<n; i++){
        if (a[i] == a[N]-1){
            ans++;
            i++;
            continue;
        }
    }
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	freopen("input.txt", "r", stdin);

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
