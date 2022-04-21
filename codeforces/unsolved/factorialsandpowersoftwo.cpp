#include <bits/stdc++.h>
using namespace std;

const int MX = 1e12+5;
int dp[MX];

set<long long> a;
void solve(){
    long long n; cin >> n;

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	freopen("input.txt", "r", stdin);

    auto fact = [](int a){
        long long ans=1;
        for (int i=1; i<=a; i++)
            ans *= i;
        return ans;
    };

    for (int i=1; i<15; i++) a.insert(fact(i));
    for (int i=0; i<40; i++) a.insert(pow(2, i));
    // recursive dp?

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
