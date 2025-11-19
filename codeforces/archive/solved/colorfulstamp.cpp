#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    for (int i=0; i<n; i++){
        if (s[i] == 'W') s[i] = ' ';
    }

    vector<string> result;
    istringstream iss(s);
    for(string s; iss >> s; )
        result.push_back(s);

    if ((int)result.size() == 0){
        cout << "YES" << endl;
        return;
    }

    for (string ss : result){
        if (ss.find('B') == string::npos or ss.find('R') == string::npos){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

