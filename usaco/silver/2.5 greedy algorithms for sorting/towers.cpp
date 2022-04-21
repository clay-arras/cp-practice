#include <bits/stdc++.h>
using namespace std;

int main(){
    ios:: sync_with_stdio(0), cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

    int n; cin >> n;
    multiset<int> towers;
    
    for (int i=0; i<n; i++){
        int t; cin >> t;
        auto it = towers.upper_bound(t);
        if (it != towers.end()){
            towers.erase(it);
        }
        towers.insert(t);
    }
    cout << (int)towers.size() << endl;
}
