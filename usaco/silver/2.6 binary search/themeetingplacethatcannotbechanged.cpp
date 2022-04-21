// lessons: always use double instead of float, and use setprecision
#include <bits/stdc++.h>
using namespace std; 

int n;
vector<pair<int, int>> friends;

double check(double point){
    double max_time=abs(friends[0].first - point)/friends[0].second;
    for (int i=1; i<n; i++){
        max_time = max(max_time, abs(friends[i].first - point)/friends[i].second);
    }
    return max_time;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    /* freopen("./io/input.txt", "r", stdin); */

    cin >> n;
    int max_point=0;
    int a[n]; for (int& t : a) cin >> t;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        friends.push_back({a[i], t});
        max_point = max(max_point, a[i]);
    }
    sort(friends.begin(), friends.end());

    double x = -1;
    for (double b = max_point+1; b >= 1e-7; b /= 2) {
        while (check(x+b) > check(x+b+1e-7)) {
            x += b;
        }
    }
    cout << setprecision(20) << check(x) << endl;; 
}	
