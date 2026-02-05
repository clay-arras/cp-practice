#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<class T>
struct SegTree {
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; }
    vector<T> tree; int n;
    SegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}
    void update(int pos, T val) {
        for (tree[pos += n] = val; pos /= 2;)
            tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
    }
    T query(int b, int e) {
        e++;
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, tree[b++]);
            if (e % 2) rb = f(tree[--e], rb);
        }
        return f(ra, rb);
    }
};

const int MX = 2e5+9;
vector<int> adj_list[MX];
bool visited[MX];

int timer = 0, st[MX], en[MX];
void dfs1(int node, int parent) {
    st[node] = timer++;
    for (int i : adj_list[node]) {
        if (i != parent) 
            dfs1(i, node); 
    }
    en[node] = timer - 1;
}

int N;
SegTree<long long> tree;
vector<long long> A, dp0;

void dfs2(int x) {
    visited[x] = true;
    
    vector<pair<long double, int>> eord;
    for (int i : adj_list[x]) 
        if (!visited[i])
            eord.push_back({tree.query(st[i], en[i])*1.0L/(en[i] - st[i] + 1), i});
    sort(eord.rbegin(), eord.rend());

    long long sum = 0, pref = 0;
    for (long long i=0; i<(int)eord.size(); i++) {
        int idx = eord[i].second;
        dfs2(idx);
        sum += dp0[idx] + tree.query(st[idx], en[idx]) * (pref+1);
        pref += 2*(en[idx] - st[idx] + 1);
    }
    dp0[x] = sum;
}

template<class T>
vector<T> BFS(T src) {
    const T mxV = INT_MAX;
    queue<int> q;
    vector<T> dist(N, mxV);
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int t : adj_list[x]) {
            if (dist[t] == mxV) {
                dist[t] = dist[x] + 1;
                q.push(t);
            }
        }
    }
    return dist;
}

vector<int> is_path;
int mxd;
bool dfs3(int x, int d=0) {
    is_path[x] = 0;

    bool ok = (d == mxd);
    for (int i : adj_list[x]) 
        if (is_path[i] == 2) 
            ok |= dfs3(i, d+1);
    if (ok) is_path[x] = 1;
    return ok;
}


vector<long long> dp1;
void dfs4(int x) {
    visited[x] = true;

    vector<pair<long double, int>> eord;
    for (int i : adj_list[x]) {
        if (!visited[i]) {
            pair<long double, int> cmp = {tree.query(st[i], en[i])*1.0L/(en[i] - st[i] + 1), i};
            eord.push_back(cmp);
        }
    }
    sort(eord.rbegin(), eord.rend());

    int M = (int)eord.size();
    vector<long long> szp(M+1, 0), ctp(M+1, 0);
    for (int i=M-1; i>=0; i--) {
        int idx = eord[i].second;
        
        szp[i] = szp[i+1] + 2*(en[idx] - st[idx] + 1);
        ctp[i] = ctp[i+1] + tree.query(st[idx], en[idx]);
    }
    for (auto [r, i] : eord) 
        dfs4(i);

    long long ans = LLONG_MAX;
    for (int idx=0; idx<M; idx++) {
        int i = eord[idx].second;
        if (is_path[i]) {
            long long sz = 2*(en[i]-st[i]+1);
            long long ct = tree.query(st[i], en[i]);
            long long prior = dp0[x] + (dp1[i] - dp0[i]);
            ans = min(ans, prior - sz*ctp[idx+1] + szp[idx+1]*ct);
        }
    }
    if (ans == LLONG_MAX) {
        dp1[x] = (is_path[x] ? dp0[x] : LLONG_MAX);
    } else {
        dp1[x] = ans;
    }
}


void solve() {
    int T; cin >> N >> T; 

    A = vector<long long>(N, 0);
    for (int i=1; i<N; i++) {
        int p; cin >> p >> A[i];
        --p;
        adj_list[p].push_back(i);
        adj_list[i].push_back(p);
    }

    dfs1(0, -1);
    tree = SegTree<long long>(N, 0);
    for (int i=0; i<N; i++)
        tree.update(st[i], A[i]);

    dp0 = vector<long long>(N, 0);
    dfs2(0);

    if (T == 0) {
        cout << 2*(N-1) << " " << dp0[0] << endl;

    } else if (T == 1) {
        auto dist = BFS<int>(0);
        mxd = *max_element(dist.begin(), dist.end());

        is_path = vector<int> (N, 2);
        dfs3(0);

        fill(visited, visited+N, false);
        dp1 = vector<long long>(N, 0);
        dfs4(0);
        cout << 2*(N-1) - mxd << " " << dp1[0] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
