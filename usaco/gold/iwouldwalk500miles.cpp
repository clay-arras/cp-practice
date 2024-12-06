#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long F1 = 2019201913LL;
const long long F2 = 2019201949LL;
const long long MOD = 2019201997;
long long calc_length(long long a, long long b) {
	return (++a * F1 + ++b * F2) % MOD;
}

int N, K;
vector<long long> Prim() {
    vector<bool> visited(N, false);
    vector<long long> dist(N, MOD);
    for (int i=0; i<N; i++) {
        int minI = -1;
        for (int j=0; j<N; j++) {
            if ((minI < 0 or dist[j] < dist[minI]) and !visited[j])
                minI = j;
        }
        visited[minI] = true;
        for (int j=0; j<N; j++) {
			if (!visited[j])
                dist[j] = min(dist[j], calc_length(min(minI, j), max(minI, j)));
        }
    }
    return dist;
}

void solve() {
    cin >> N >> K;
    vector<long long> e = Prim();
    sort(e.begin(), e.end());
    cout << e[N-K] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    /* freopen("walk.in", "r", stdin); */
    /* freopen("walk.out", "w", stdout); */

    int t=1;
    while (t--) {
        solve();
    }
}

/*

Half credit solution. Ran into memory limit issues

long long dist(long long x, long long y) {
    return (2019201913*1LL*x%2019201997 + 2019201949*1LL*y%2019201997)%2019201997;
}

long long N, K;
long long Kruskals (long long N, vector<pair<long long, pair<int, int>>> e) {
    sort(e.begin(), e.end());
    DSU D; D.init(N+1);

    int CC = N;
    bool ok = false;
    for (auto &a : e) {
        if (D.unite(a.second.first, a.second.second)) {
            if (ok)
                return a.first;
            if (--CC == K)
                ok = true;
        }
    }
    return -1;
}

void solve() {
    cin >> N >> K;

    vector<pair<long long, pair<int, int>>> e;
    for (int i=1; i<=N; i++)
        for (int j=i+1; j<=N; j++)
            e.push_back({dist(i, j), {i, j}});

    cout << Kruskals(N, e) << endl;
}


*/
