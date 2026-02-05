#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2e5+9;
vector<int> adj_list[MX];
bool visited[MX];

int N, mxd;
vector<long long> A, is_path, dp0, dp1, pref;

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

int timer = 0, st[MX], en[MX];
void dfs1(int node, int parent) {
    st[node] = timer++;
    for (int i : adj_list[node]) {
        if (i != parent) 
            dfs1(i, node); 
    }
    en[node] = timer - 1;
}

void dfs2(int x) {
    visited[x] = true;
    
    vector<pair<long double, int>> eord;
    for (int i : adj_list[x]) {
        if (!visited[i]) {
            long long sz = (en[i] - st[i] + 1);
            long long ct = (pref[en[i]+1] - pref[st[i]]);
            eord.push_back({ct*1.0L/sz, i});
        }
    }
    sort(eord.rbegin(), eord.rend());

    long long sum = 0, roll = 0;
    for (long long i=0; i<(int)eord.size(); i++) {
        int idx = eord[i].second;
        dfs2(idx);
        sum += dp0[idx] + (pref[en[idx]+1] - pref[st[idx]]) * (roll+1);
        roll += 2*(en[idx] - st[idx] + 1);
    }
    dp0[x] = sum;
}

bool dfs3(int x, int d=0) {
    is_path[x] = 0;

    bool ok = (d == mxd);
    for (int i : adj_list[x]) 
        if (is_path[i] == 2) 
            ok |= dfs3(i, d+1);
    if (ok) is_path[x] = 1;
    return ok;
}


void dfs4(int x) {
    visited[x] = true;

    vector<pair<long double, int>> eord;
    for (int i : adj_list[x]) {
        if (!visited[i]) {
            long long sz = (en[i] - st[i] + 1);
            long long ct = (pref[en[i]+1] - pref[st[i]]);
            eord.push_back({ct*1.0L/sz, i});
        }
    }
    sort(eord.rbegin(), eord.rend());

    int M = (int)eord.size();
    vector<long long> szp(M+1, 0), ctp(M+1, 0);
    for (int i=M-1; i>=0; i--) {
        int idx = eord[i].second;
        
        szp[i] = szp[i+1] + 2*(en[idx] - st[idx] + 1);
        ctp[i] = ctp[i+1] + pref[en[idx]+1] - pref[st[idx]];
    }
    for (auto [r, i] : eord) 
        dfs4(i);

    long long ans = LLONG_MAX;
    for (int idx=0; idx<M; idx++) {
        int i = eord[idx].second;
        if (is_path[i]) {
            long long sz = 2*(en[i]-st[i]+1);
            long long ct = pref[en[i]+1] - pref[st[i]];
            long long prior = dp0[x] + (dp1[i] - dp0[i]);
            ans = min(ans, prior - sz*ctp[idx+1] + szp[idx+1]*ct);
        }
    }
    dp1[x] = (ans == LLONG_MAX ? 0 : ans); 
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

    pref = vector<long long>(N+1, 0);
    vector<long long> orig(N);
    for (int i=0; i<N; i++)
        orig[st[i]] = A[i];
    for (int i=1; i<=N; i++)
        pref[i] = pref[i-1] + orig[i-1];

    dp0 = vector<long long>(N, 0);
    dfs2(0);

    if (T == 0) {
        cout << 2*(N-1) << " " << dp0[0] << endl;

    } else if (T == 1) {
        auto dist = BFS<int>(0);
        mxd = *max_element(dist.begin(), dist.end());

        is_path = vector<long long> (N, 2);
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
