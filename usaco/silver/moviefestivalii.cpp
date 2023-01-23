#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.second != b.second) return a.second < b.second;
    return a.first > b.first;
}

int main(){
    ios:: sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, k; cin >> n >> k;
    multiset<int> watchers;
    vector<pair<int, int>> movies;

    for (int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        movies.push_back({b, a});
    }
    sort(movies.begin(), movies.end());
    for (auto [u, v] : movies) cout << v << " " << u << endl;
    cout << endl;

    int ans=0;
    for (int i=0; i<n; i++){
        int begin_t = movies[i].second;
        auto it = watchers.upper_bound(begin_t);        

        cout << *it << " ";;
        if (it == watchers.end() and (int)watchers.size() < k){
            watchers.insert(movies[i].first);
            ans++;
            cout << 1;
        }
        else if (it == watchers.begin() and *it < begin_t){
            watchers.erase(it);
            watchers.insert(movies[i].first);
            ans++;
            cout << 2;
        }
        else if (it != watchers.begin()){
            prev(it, 1);
            watchers.erase(it);
            watchers.insert(movies[i].first);
            ans++;
            cout << 3;
        }else cout << 4;
        cout << " " << ans << ": ";
        for (int t : watchers) cout << t << " ";
        cout << endl;
    }
    cout << ans << endl; 
}

// notes: what do we want: 
// lower bound: greater than or equal to
// upper bound: greater than (strictly)
//
// make a multiset which (if you can add) and if you can't find a thing lower than it
// first item in the multiset which is lower than the movies[i].second (first starting time)
// how to find first item less than 
