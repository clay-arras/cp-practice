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
    int N, K; cin >> N >> K;
    string s; cin >> s;

    /* DSU d; d.init(N); */
    string ans = s;
    if (s[0] - 'a' >= K) {
        for (int i=0; i<N; i++) {
            if (s[i] <= s[0] and s[0] - K < ans[i])
                ans[i] = s[0] - K;
        }
        cout << ans << endl;
    } else {
        K -= s[0] - 'a';
        for (int i=1; i<N; i++) {
            if (s[i] > s[0]) {
                int sub = min(s[i]-s[0], K);
                ans[i] -= sub;
                K -= sub;
            }
            if (!K)
                break;
        }
        K = s[0] - 'a';
        for (int i=0; i<N; i++) {
            if (s[i] <= s[0] and s[0] - K < ans[i])
                ans[i] = s[0] - K;
        }
        cout << ans << endl;
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

DSU the same letters together
The most optimal solution always involves increasing the first value
However we also add the number of values that can be increased afterwards to the first value

If (A[0] - 'a' > k) then we only decrease the first one
Else we loop through the second and third ones and see if we can do (A[i] - A[0])

Every value less than this value is decreased to 'a'
We can decrease other values together

 */
