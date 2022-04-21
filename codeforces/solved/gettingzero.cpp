#include <bits/stdc++.h>
using namespace std;

const int MX = (1 << 15);
void solve(){
    long long t; cin >> t;

    int dist=15;
    vector<int> arr(16, 0);
    for (int j=0; j<16; j++) arr[j] = t + j;

    for (int j=0; j<16; j++){
        long long a = arr[j];
        int cnt=j;

        a %= MX;
        while (a){
            a *= 2;
            a %= MX;
            cnt++;
        }
        dist = min(dist, cnt);
    }
    cout << dist << " ";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int n; cin >> n;
    while(n--){
        solve();
    }
}
