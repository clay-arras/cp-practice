#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> b;
    vector<int> r;

    int a[n]; for (int& t : a) cin >> t;
    string s; cin >> s;
    for (int i=0; i<n; i++){
        if (s[i] == 'B') b.push_back(a[i]);
        else if(s[i] == 'R') r.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    sort(r.rbegin(), r.rend());

    set<int> st;
    for (int i=1; i<=n; i++) st.insert(i);

    for (int i=0; i<(int)r.size(); i++){
        auto it = st.end();
        --it;
        if (*it >= r[i]){
            st.erase(it);
        }else{
            cout << "NO" << endl;
            return;
        }
    }

    for (int i=0; i<(int)b.size(); i++){
        auto it = st.begin();
        if (*it <= b[i]){
            st.erase(it);
        }else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while(t--){
        solve();
    }
}
