#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, b, r; cin >> n >> r >> b;

    // maximum
    int ratio = ceil(r*1.0/(b+1)) + 1;
    int neg = max(0, ratio*b - n)*(ratio-1);

    for (int i=1; i<=n; i++){
        if (neg > 0){
            cout << ((i%(ratio-1)) ? "R" : "B");
            neg--;
        }else{
            cout << ((i%ratio) ? "R" : "B");
        }
    }
    cout << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
