#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;

    int n = (int)s.size();
    int cnt = 1;
    if (n == 1){
        cout << "NO" << endl;
        return;
    }

    for (int i=1; i<n; i++){
        if (s[i] == s[i-1]) { cnt++;
        }else{
            if (cnt == 1){
                cout << "NO" << endl;
                return;
            }
            cnt = 1;
        }
    }
    if (cnt == 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
