#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MOD = 1e9+7;
const int MX = 2e5+67;
unordered_map<int, vector<long long>> pre;
unordered_set<int> ms;

void solve(string S, int M) {
    int N = (int)S.size();

    vector<long long> A(10, 0);
    for (int i=0; i<N; i++) 
        A[S[i]-'0']++;

    long long ans = 0;
    for (int i=0; i<10; i++) 
        ans += (A[i] * pre[M][i]) % MOD;
    cout << (ans % MOD) << endl;
}

void precomp() {
    deque<pair<int, vector<long long>>> dq; 
    for (int i=0; i<10; i++) {
        vector<long long> t(10, 0);
        t[i] = 1;
        dq.push_back({i, t});
    }
    auto addmod = [&](const vector<long long>& a, 
            const vector<long long>& b) {
        vector<long long>t(10, 0);
        for (int i=0; i<10; i++)
            t[i] = (a[i] + b[i]) % MOD;
        return t;
    };

    auto snap = [&](int m, 
            const deque<pair<int, vector<long long>>>& dq) { // this is weird
        if (pre.count(m))
            return;
        pre[m] = vector<long long>(10, 0);
        deque<pair<int, vector<long long>>> dcp(dq.begin(), dq.end()); 

        while (!dcp.empty()) {
            auto x = dcp.back();
            dcp.pop_back();
            for (int i=0; i<10; i++)
                pre[m][i] = (pre[m][i] + x.second[i]) % MOD; 
        }
    };

    for (int i=0; i<MX; i++) {
        if (ms.count(i))
            snap(i, dq);

        auto x = dq.back();
        dq.pop_back();

        auto y = dq.front();
        dq.pop_front();
        dq.push_front({y.first, 
                addmod(x.second, y.second)});
        dq.push_front(x);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");
    
    int t; cin >> t;
    vector<pair<string, int>> in;
    for (int i=0; i<t; i++) {
        string S; cin >> S;
        int M; cin >> M;
        in.push_back({S, M});
        ms.insert(M);
    }
    precomp();

    for (int i=0; i<t; i++) {
        solve(in[i].first, in[i].second);
    }
}
