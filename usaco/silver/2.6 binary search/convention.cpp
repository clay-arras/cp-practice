#include <bits/stdc++.h>
using namespace std; 

int N, M, C;
vector<int> arr;

bool check(int dist){
    int count=0, buses=0, p=0;
    for (int i=0; i<N; i++){
        if (count >= C or arr[i] - arr[p] > dist){
            p = i;
            count=0;
            buses++;
        }else count++;
    }
    cout << buses << endl;
    return buses <= M;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("./io/input.txt", "r", stdin);

    cin >> N >> M >> C;
    for (int i=0; i<N; i++){
        int t; cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    // assign each cow to its own bus
    // assign all cows to one bus (or sim)
    // how to distribute cows;
    // greatest distance between adjacent cows

    for (int i=0; i<20; i++){
        check(i);
    }
}
