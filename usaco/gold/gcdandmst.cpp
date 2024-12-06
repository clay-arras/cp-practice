#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct DSU {
    vector<int> e;
    void init(int N) {
        e = vector<int>(N,-1);
    }
    int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }
    int size(int x) {
        return -e[get(x)];
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x,y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

void solve() {
    long long N, P; cin >> N >> P;

    vector<int> A(N);
    for (int& t : A)
        cin >> t;

    vector<pair<int, int>> arr;
    for (int i=0; i<N; i++)
        arr.push_back({A[i], i});
    sort(arr.begin(), arr.end());

    long long ans = 0, cc = N;
    DSU D; D.init(N);
    for (auto t : arr) {
        int i = t.second;
        if (t.first >= P)
            break;

        for (int j=i+1; j<N; j++) {
            if (D.get(j) == D.get(i) or gcd(A[j], A[i]) != A[i])
                break;
            cc -= D.unite(i, j);
            ans += A[i];
        }
        for (int j=i-1; j>=0; j--) {
            if (D.get(j) == D.get(i) or gcd(A[j], A[i]) != A[i])
                break;
            cc -= D.unite(i, j);
            ans += A[i];
        }
    }
    cout << ans + P*(cc - 1) << endl;
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

Sort and process edges that are guaranteed to be less
We start at the lowest values and expand outwaards, and we for cycles meaning we only process O(N) edges because for every value we arrive at we add to the graph


*/
