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
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    map<int, vector<int>> m;
    for (int i=0; i<N; i++)
        m[A[i]].push_back(i);
    for (auto [k, v] : m)
        sort(m[k].rbegin(), m[k].rend(), [&](int a, int b) {
            int a_mx = 0, b_mx = 0;
            if (a-1 >= 0) a_mx = max(a_mx, A[a-1]);
            if (a+1 < N) a_mx = max(a_mx, A[a+1]);
            if (b-1 >= 0) b_mx = max(b_mx, A[b-1]);
            if (b+1 < N) b_mx = max(b_mx, A[b+1]);

            return a_mx < b_mx;
        });
    
    vector<bool> visited(N, false);
    DSU d; d.init(N);
    int ans = 0;
    for (auto it=m.rbegin(); it!=m.rend(); ++it) {
        auto [k, v] = *it;

        deque<int> dq(v.begin(), v.end());
        while (!dq.empty()) {
            int i = dq.front(); dq.pop_front();
            if (visited[i]) continue;

            if (i-1 >= 0 && visited[i-1]) {
                d.unite(i, i-1);
                visited[i] = true;
            }
            if (i+1 < N && visited[i+1]) {
                d.unite(i, i+1);
                visited[i] = true;
            }
            if (!visited[i]) {
                ans++;
                visited[i] = true;
            }


            if (i-1 >= 0 && A[i] == A[i-1] && !visited[i-1]) 
                dq.push_front(i-1);
            if (i+1 < N && A[i] == A[i+1] && !visited[i+1]) 
                dq.push_front(i+1);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}


/*

DSU d;
vector<bool> visited;
map<int, vector<int>> m;

for each index:
- if left is visited, then join left and this index and mark visited
- if right is visited, then join right and this index and mark visited
- if !visited, increment answer and mark visited

---

problem: 
the processing order isn't right because we need to do some sort of deque...
- if the previously processed number's neighbor is the same value and
  unprocessed, then we want to put it to the start of the queue

*/
