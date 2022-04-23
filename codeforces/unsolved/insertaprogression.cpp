#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    if (n == 1) {
        cout << max(a[0], x) - min(a[0], 1) << endl;
        return;
    }

    int ans=0;
    set<pair<int, int> > s;
    for (int i=1; i<n; i++){
        pair<int, int> temp = make_pair(max(a[i], a[i-1]), min(a[i], a[i-1]));
        s.insert(temp);

        ans += abs(a[i] - a[i-1]);
    }

    cout << endl;
    for (int i=1; i<=x; i++){
        pair<int, int> temp = *lower_bound(s.begin(), s.end(), make_pair(i, 0));
        cout << i << " " << temp.first << " " << temp.second << endl;
        if (temp.first >= i and temp.second <= i){
            /* cout << i << " "; */
            continue;
        }
        cout << i << endl;
        ans += (abs(temp.first - i) + abs(temp.second - i)) - (temp.first-temp.second);
    }
    cout << ans << endl;
    /* cout << 0; */

    // every distance away from the boundary point is 2x more points
    // put all intervals into a set of pairs
    // and then use lower bound to find things
    // iterate through 1-x
    //
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);

    int t; cin >> t;
    while (t--){
        solve();
    }
}

