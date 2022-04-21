#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

#ifndef ONLINE_JUDGE
	void __print(int x) {cerr << x;}
	void __print(long long x) {cerr << x;}
	void __print(float x) {cerr << x;}
	void __print(double x) {cerr << x;}
	void __print(bool x) {cerr << (x ? "true" : "false");}
	void __print(char x) {cerr << '"' << x << '"';}
	void __print(const string &x) {cerr << '\"' << x << '\"';}

	template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
	template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}

	void _print() {cerr << "]\n";}
	template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

	#define _cerr() cerr << "\n";
	#define debug(x...) cerr << "L(" << __LINE__ << "): [" << #x << " = "; _print(x);
	#else
	#define debug(x...)
#endif

void solve(){
	int COWS, SELL, RENT; cin >> COWS >> SELL >> RENT;
	vector<long long> cows(COWS);
	vector<pi> sell(SELL);
	vector<long long> rent(RENT);

	for (auto& t:cows) cin >> t;
	for (auto& t:sell) cin >> t.second >> t.first;
	for (auto& t:rent) cin >> t;

	sort(cows.rbegin(), cows.rend());
	sort(sell.rbegin(), sell.rend());
	sort(all(rent));

	long long sum=0;
	int sell_count=0;
	for (int i=0; i<COWS; i++){
		long long add=0;
		int cow_milk = cows[i];

		if (i < SELL){
			while(cow_milk > 0){

				int& amount_left = sell[sell_count].second;
				int a = min(cow_milk, amount_left);

				add += a * sell[sell_count].first;
				cow_milk -= a;
				amount_left -= a;

				if (!amount_left and sell_count != SELL) sell_count++;
			}
		}
		if (i > COWS-RENT){
			add = max(add, rent[COWS-i]);
		}
		sum += add;
	}



	cout << sum << "\n";
}
// 	int iShop = 0;
// 	int iRent = 0;
// 	int i = 0;
// 	ll sol = 0;
// 	while (i < n) {
// 		int litres = production[i];
// 		int moneyT = 0, curI = iShop;
// 		int last = 0;
// 		while (curI < m) {
// 			int rest = min(litres, shops[curI].second);
// 			moneyT += shops[curI].first * rest;
// 			litres -= rest;

// 			if (litres == 0) {
// 				last = rest;
// 				break;
// 			} else {
// 				curI++;
// 			}
// 		}

// 		if (iRent >= r || moneyT > rent[iRent]) {
// 			sol += moneyT;
// 			iShop = curI;
// 			if (iShop < m) shops[iShop].second -= last;
// 			i++;
// 		} else {
// 			sol += rent[iRent];
// 			n--;
// 			iRent++;
// 		}
// 	}

// 	cout << sol << '\n';
// }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

   	int t=1;
   	while(t--){
   		solve();
   	}
	return 0;
}