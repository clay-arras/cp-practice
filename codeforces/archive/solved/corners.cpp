#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

const int MX = 500;
int a[MX][MX];

int dx[] = {1, 1, -1, -1};
int dy[] = {-1, 1, -1, 1};

void solve(){
    int n, m; cin >> n >> m;

    int ones = 0;
    int case_ = 2;
    for (int i=0; i<n; i++){
        string t; cin >> t;
        for (int j=0; j<m; j++){
            int v = t[j]-'0';
            a[i][j] = v;
            if (v) ones++;
            else case_ = min(case_, 1);
        }
    }

    map<int, set<int> > x, y;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (a[i][j] == 0){
                x[i], y[j];
                if (x[i].empty()){
                    x[i].insert(j);
                }else{
                    for (int v : x[i]){
                        if (abs(v-j) == 1){
                            case_ = min(case_, 0);
                        }
                    }
                }
                if (y[j].empty()){
                    y[j].insert(i);
                }else{
                    for (int v : y[j]){
                        if (abs(v-i) == 1){
                            case_ = min(case_, 0);
                        }
                    }
                }
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (a[i][j] == 1){
                for (int v=0; v<4; v++){
                    int x1 = i+dx[v];
                    int y1 = j+dy[v];

                    if (x1>=0 and x1<n and y1>=0 and y1<m)
                        if (a[i][y1] == 0 and a[x1][j] == 0){
                            case_ = min(case_, 0);
                        }
                }
            }
        }
    }

    cout << ones - case_ << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
