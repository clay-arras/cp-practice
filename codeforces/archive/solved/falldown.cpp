#include <bits/stdc++.h>
using namespace std;

const int mxN = 50;
int n, m;
char grid[mxN][mxN];
void fallDown(int x, int y){
    if (x+1 <= n-1 and grid[x+1][y] == '.'){
        grid[x][y] = '.';
        grid[x+1][y] = '*';
        fallDown(++x, y);
    }
}

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void solve(){
    cin >> n >> m;

    vector<pair<int, int>> rocks;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> grid[i][j];
            if (grid[i][j] == '*'){
                rocks.push_back({i, j});
            }
        }
    }
    sort(rocks.begin(), rocks.end(), cmp);
    for (auto a : rocks){
        fallDown(a.first, a.second);
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){ cout << grid[i][j]; }
        cout << endl;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

