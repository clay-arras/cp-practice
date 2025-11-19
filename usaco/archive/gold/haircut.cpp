#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type,
      less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve(){
    int N; cin >> N;

    vector<int> A(N);
    for (int &t : A)
        cin >> t;

    long long sum = 0;
    oset<pair<int, int>> s;
    vector<long long> inv(N+1, 0);

    for (int i=0; i<N; i++){
        s.insert({A[i], i});
        inv[A[i]] += i - s.order_of_key({A[i], i});
        sum += i - s.order_of_key({A[i], i});
    }

    vector<long long> ans;
    for (int i=N-1; i>=0; i--)
        ans.push_back(sum -= inv[i]);

    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    /* freopen("haircut.in", "r", stdin); */
    /* freopen("haircut.out", "w", stdout); */

    int t=1;
    while(t--){
        solve();
    }
}

