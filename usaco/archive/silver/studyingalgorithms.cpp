#include <bits/stdc++.h>
using namespace std;

int main(){
    ios:: sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int N, X; cin >> N >> X;
    int alg[N]; for (int& t:alg) cin >> t;

    sort(alg, alg+N);
    int ans=0;
    int sum=0;
    for (int i=0; i<N; i++){
        if (sum+alg[i] > X) break;
        sum += alg[i];
        ans++;
    }
    cout << ans << endl;
}

