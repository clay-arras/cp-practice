#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

// what if the solution has similar stuff
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> col;
    for (int i=0; i<n and col.empty(); i++){
        vector<int> t = a[i];
        sort(t.begin(), t.end());

        for (int j=0; j<m; j++){
            if (t[j] != a[i][j]){
                col.push_back(j);
            }
        }
    }
    if (col.empty()){
        cout << "1 1\n";
        return;
    }
    if ((int)col.size() > 2){
        cout << -1 << "\n";
        return;
    }

    for (int i=0; i<n; i++){
        iter_swap(a[i].begin() + col[0], a[i].begin() + col[1]);
        if (!is_sorted(a[i].begin(), a[i].end())){
            cout << -1 << "\n";
            return;
        }
    }
    cout << col[0] + 1 << " " << col[1] + 1 << "\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
// brute force algo:
// sort each column, compare to original rows, if there is 2 difference, mark which indices they are different at
// check if that is consistent throughout the rows
// only sort one
// once we get indices, we swap them and check is_sorted
