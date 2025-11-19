#include <bits/stdc++.h>
using namespace std; 

struct Point{
	int x, y;
	int cx, cy;
};

bool sortX(Point a, Point b){
	return a.x < b.x;
}
bool sortY(Point a, Point b){
	return a.y < b.y;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	// freopen("split.in", "r", stdin);
    // freopen("split.out", "w", stdout);
   	int N; cin >> N;

   	vector<Point> coords(N);
   	for (auto &t:coords) cin >> t.x >> t.y;

   	sort(coords.begin(), coords.end(), sortX);
	for (int i=0; i<N; i++) coords[i].cx = i+1;
	sort(coords.begin(), coords.end(), sortY);
	for (int i=0; i<N; i++) coords[i].cy = i+1;

	for (int i=0; i<N; i++){
		// 0 - i we include in rectangle 1
		// i+1 - N we include in rectangle 2
		// find the largest in each "rectangle"
	}




   	

}