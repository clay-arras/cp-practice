// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	int p[N];

	for (int &t : p) cin >> t;

	int count = 0, sum, avg;
	for (int i=0; i<N; i++){
		for (int j=i; j<N; j++){
			sum = 0;
			for (int k=i; k<=j; k++) sum += p[k];
			if (sum%(j-i+1) != 0) continue;

			avg = sum/(j-i+1);
			for (int k=i; k<=j; k++){
				if (avg == p[k]){
					count++;
					break;
				}
			}
		}	
	}
	cout << count << endl;
}
