#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 1e3+5;
int Gp[MX][MX], G[MX][MX];
int C, R;
void reverseColumns() {
    for (int i=0; i<C; i++)
        for (int j=0, k=C-1; j<k; j++, k--)
            swap(Gp[j][i], Gp[k][i]);
}
void transpose() {
    for (int i=0; i<R; i++)
        for (int j=i; j<C; j++)
            swap(Gp[i][j], Gp[j][i]);
}
void rotate180() {
    transpose();
    reverseColumns();
    transpose();
    reverseColumns();
}

void solve() {
    long long N, K; cin >> N >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> G[i][j];
            Gp[i][j] = G[i][j];
        }
    }
    C = N, R = N;
    rotate180();

    long long sum = 0;
    for (int i=0; i<N/2; i++)
        for (int j=0; j<N; j++)
            sum += (int)(G[i][j] != Gp[i][j]);

    if (N%2 == 1)
        for (int j=0; j<N/2; j++)
            sum += (int)(G[N/2][j] != G[N/2][N-1-j]);

    if (sum <= K) {
        if (sum == K)
            cout << "YES" << endl;
        else if (N%2 == 1)
            cout << "YES" << endl;
        else if ((K - sum) % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*



*/
