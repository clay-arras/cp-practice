#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    int table[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> table[i][j];
        }
    }
    if (table[0][0]){
        cout << -1 << endl;
        return;
    }
    // store coords?
    // which way to do it
    // right to left
    // have to to multiple ways... for the first column
    for (int i=0; i<n; i++){
        for (int j=1; j<m; j++){

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
