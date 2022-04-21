// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

struct Rect{
	int x1, y1, x2, y2;
};
int area(Rect a){
	return abs(a.x1-a.x2)*abs(a.y1-a.y2);
}
int intersect (Rect a, Rect b){
	return max(min(a.x2, b.x2) - max(a.x1, b.x1), 0) * max(min(a.y2, b.y2) - max(a.y1, b.y1), 0);
}

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	Rect b1, b2, t;
	cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
	cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
	cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

	cout << area(b1) + area(b2) - intersect(b1, t) - intersect(b2, t);
}
