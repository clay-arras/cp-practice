#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6+5;
int n, m, c=0;
vector<int> a[MX][2];

long fact(long k){
    int i, fact = 1;
    for(i = k; i>1; i--) fact *= i;
    return fact;
}
long nCr(long v, long r){
    long nume = 1, i;
    for(i = v; i>r; i--) nume *= i;
    return long(nume/fact(v-r));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);
    
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int t; cin >> t;
            --t;
            a[t][0].push_back(i+1);
            a[t][1].push_back(j+1);
            c = max(t, c);
        }
    }
    // might be too slow... use a set if it is
    for (int i=0; i<=c; i++){
        sort(a[i][0].begin(), a[i][0].end()); 
        sort(a[i][1].begin(), a[i][1].end());
    }

    // crazy evil combinatorics type thing down here, iterate through pairs and do stuff
    int ans=0;
    for (int i=0; i<=c; i++){
        for (int k=0, len = (int)a[i][0].size(); k<len-1; k++){
            ans += nCr(len-2, k) * (a[i][0][k+1] - a[i][0][k]);  
            cout << (a[i][0][k+1] - a[i][0][k]) << endl;
            /* cout << k << " " << len-2 << endl; */
        }
        for (int k=0, len = (int)a[i][1].size(); k<len-1; k++){
            ans += nCr(len-2, k) * (a[i][1][k+1] - a[i][1][k]);  
        }
    }
    cout << ans << endl;
}
