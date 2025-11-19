#include <bits/stdc++.h>
using namespace std;

int main(){
    ios:: sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int n; cin >> n;
    vector<pair<int, int>> movies;

    for (int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        movies.push_back({b, a});
    }
    sort(movies.begin(), movies.end());

    int ans=0, t=0;
    for (int i=0; i<n; i++){
        if (t <= movies[i].second){
            t = movies[i].first;
            ans++;
        }
    }
    cout << ans << endl;
}

