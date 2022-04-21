// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
struct Rect{
	int x1, y1, x2, y2;
	int w;
	int h;
};

void solve(){
	int W, H; cin >> W >> H;
	Rect a; cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	int w, h; cin >> w >> h;

	a.w = a.x2-a.x1;
	a.h = a.y2-a.y1;

	int ans = INT_MAX;
	if (w + a.w > W && h + a.h > H){
		cout << -1 << endl;
		return;
	}

	if (h + a.h <= H) ans = min({ans, h - a.y1, a.y2 - (H-h)});
	if (w + a.w <= W) ans = min({ans, w - a.x1, a.x2 - (W-w)});
 	ans = max(ans, 0);
	 
	cout << ans << endl;
}


int main() {
	int t; cin >> t;
	while(t--){
		solve();
	}
}
