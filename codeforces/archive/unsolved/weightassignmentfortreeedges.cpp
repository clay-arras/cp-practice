#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5+5;
vector<int> ans(MX, -1);
int b[MX];
int root;

int pathSum(int m){
    int sum=0;
    m = ans[m];
    while(m != root){
        sum += m;
        m = ans[m];
        if (ans[m] == -1){
            return -1;
        }
    }
    return sum;
}

void solve(){
    int n; cin >> n;
    for (int i=0; i<n; i++){
        cin >> b[i];
        --b[i];
    }
    int p[n]; 
    for (int i=0; i<n; i++){
        cin >> p[i];
        --p[i];
    }

    auto rootFind = [](){
        int prev=0;
        int x=b[0];
        while(x != prev){
            prev = x;
            x = b[x];
        }
        return x;
    };
    root = rootFind();

    // prev sum
    // do prevsum - (sum of path) + 1 
    // if one of the path isn't defined then it is impossible
    int prev_sum=0;
    for (int i=0; i<n; i++){
        int path = pathSum(p[i]);
        cout << path << endl;
        if (path == -1){
            /* cout << -1 << "\n"; */
            /* return; */
        }else{
            /* cout << "YES" << endl; */
            ans[p[i]] = prev_sum - (path) + 1;
        }
    }
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << "\n";
    fill(ans.begin(), ans.begin()+n, -1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}
