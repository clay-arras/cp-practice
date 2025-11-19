#include <bits/stdc++.h>
using namespace std;

int main(){
    ios:: sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);
    
    int N; cin >> N;
    vector<int> cards;
    
    set<int> op;
    for (int i=0; i<N; i++){
        int t; cin >> t;
        cards.push_back(t);
        op.insert(t);
    }
    set<int> bes;
    for (int i=1; i<=2*N; i++){
        if (!op.count(i)) bes.insert(i);
    }

    sort(cards.begin(), cards.begin()+N/2-1);
    sort(cards.begin()+N/2, cards.end());
    for (int t: cards) cout << t << " ";
    cout << endl;
    
    int ans=0;
    for (int i=0; i<N/2; i++){
        auto it = bes.upper_bound(cards[i]); 
        if (it != bes.end()) {
            bes.erase(it);
            cout << cards[i] << " " << *it << endl;
            ans++;
        }
    }
    for (int i=N/2; i<N; i++){
        auto it = max_element(bes.begin(), lower_bound(bes.begin(), bes.end(), cards[i])) ;
        if (it != bes.end()) {
            bes.erase(it);
            cout << cards[i] << " " << *it << endl;
            ans++;
        }

    }
    cout << ans << endl;
}

