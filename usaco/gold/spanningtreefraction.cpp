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

int N, M, A, B, C;
bool operator<(const pair<pair<int, int>, pair<int, int>> &x, const pair<pair<int, int>, pair<int, int>> &y) {
    return -x.second.first + C * x.second.second < -y.second.first + C * y.second.second;
}
vector<pair<pair<int, int>, pair<int, int>>> edges;
bool Kruskals (long double Cnew) {
    sort(edges.begin(), edges.end());
    DSU D; D.init(N+1);
    long double ans = 0;
    A = B = 0;
    C = Cnew;
    for (auto &a : edges) {
        if (D.unite(a.second.first, a.second.second)) {
            ans += -a.second.first + C * a.second.second;
            A += a.second.first;
            B += a.second.second;
            if (ans > 0)
                return false;
        }
    }
    return ans <= 0;
}
template<class T>
T lastTrue(T lo, T hi) {
    lo--;
    int cnt=64;
    for (T dif=hi-lo; dif>0 and cnt>0; dif/=2, cnt--) {
        while (lo + dif <= hi && Kruskals(lo + dif)) { lo += dif; }
    }
    return lo;
}

template<class T>
T firstTrue(T lo, T hi) {
    hi++;
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        if (Kruskals(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

long long gcd (long long x, long long y) {
    if (min(x,y) == 0) return max(x,y);
    return gcd(max(x,y) % min(x,y), min(x,y));
}
void solve() {
    cin >> N >> M;

    for (int i=0; i<M; i++) {
        int u, v, a, b; cin >> u >> v >> a >> b;
        edges.push_back({{u, v}, {a, b}});
    }
    firstTrue((long double)0, (long double)1e9);
    int g = gcd(A, B);
    cout << A/g << "/" << B/g << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*



*/
