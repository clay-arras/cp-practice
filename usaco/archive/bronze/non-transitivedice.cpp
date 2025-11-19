// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

char larger(int a[], int b[]){
	int ac=0, bc=0;
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			if (a[i] > b[j]) ac++;
			else if (b[j] > a[i]) bc++;
		}
	}
	if (ac > bc) return 'a';
	else if (ac < bc) return 'b';
	else if (ac == bc) return 't';
}

void solve(){
	int a[4], b[4];
	for (int &t : a) cin >> t;
	for (int &t : b) cin >> t;

	char greater = larger(a, b);

	int arr[8];
	for (int i=0; i<4; i++) arr[i] = a[i];
	for (int i=0; i<4; i++) arr[i+4] = b[i];

	sort(arr, arr+8);
	set<int>nums;

	for (int i=0; i<8; i++){
		nums.insert(arr[i]);
		if (arr[i]+1 <= 10) nums.insert(arr[i]+1);
		if (arr[i]-1 >= 1) nums.insert(arr[i]-1);
	}
	for (auto i : nums){
		for (auto j : nums){
			for (auto k : nums){
				for (auto l : nums){
					int c[4] = {i, j, k, l};
					if (larger(b, c) == greater && larger(c, a) == greater) {
						cout << "yes" << endl;
						return;
					}
				}
			}
		}
	}
	cout << "no" << endl;

}

int main() {
	int t; cin >> t;
	while (t--){
		solve();
	}
}
