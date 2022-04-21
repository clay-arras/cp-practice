// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

// bool cmp(pair<string, int>& a, pair<string, int>& b){
//     return a.second < b.second;
// }
string cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

int main() {
	int n; cin >> n;
	map<string, int> cow_tag;

	for (int i=0; i<7; i++){
		cow_tag.insert(pair<string, int>(cows[i], 0));
	}

	string cow; int mcount;
	for (int i=0; i<n; i++){
		cin >> cow >> mcount;
		cow_tag[cow] += mcount;
	}
	// sort(cow_tag.begin(), cow_tag.end(), cmp);

}
