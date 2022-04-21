// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Rect{
	ll x1, x2, y1, y2;
	ll area(){
		return (x2-x1)*(y2-y1);
	}
};
ll ints (Rect a, Rect b){
	return max(min(a.x2, b.x2) - max(a.x1, b.x1), (ll)0) * max(min(a.y2, b.y2) - max(a.y1, b.y1), (ll)0);
}
Rect rect_ints (Rect a, Rect b){
	Rect c; 
	c.x1 = max(max(a.x1, b.x1), (ll)0);
	c.y1 = max(max(a.y1, b.y1), (ll)0);
	c.x2 = max(min(a.x2, b.x2), (ll)0);
	c.y2 = max(min(a.y2, b.y2), (ll)0);

	return c;
}

int main() {
	Rect w, a, b;
	cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

	cout << (ints(w, a) + ints(w, b) - ints(rect_ints(a, b), w) == w.area() ? "NO" : "YES");

}
