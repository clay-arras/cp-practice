#include <bits/stdc++.h>
using namespace std;

int main(){
    ios:: sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int n; cin >> n;
    vector<pair<int, int>> tasks;

    for (int i=0; i<n; i++){
        int u, v; cin >> u >> v;
        tasks.push_back({u, v});
    }
    sort(tasks.begin(), tasks.end());

    long long time=0, ans=0;
    for (int i=0; i<n; i++){
        time += tasks[i].first;
        ans += tasks[i].second - time;
    }
    cout << ans << endl;
}
