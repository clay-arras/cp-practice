#include <bits/stdc++.h>
using namespace std;

vector<long long> k;
int n, a, b;

long long cost(int m){
    unsigned long long c = 0;
    for (int i=1; i<n; i++){
        c += b*1ULL*abs(k[min(i-1, m)] - k[i]);
    }
    c += a*1ULL*abs(k[0] - k[m]);
    return c;
}

void solve() {
    cin >> n >> a >> b;

    k.push_back(0);
    for (int i=0; i<n; i++){
        int t; cin >> t;
        k.push_back(t);
    }
    n++;

    int x = -1;
    for (int b = n; b >= 1; b /= 2) {
        while (cost(x+b-1) > cost(x+b)) x += b;
    }
    cout << cost(x) << endl;
    k.clear();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}
