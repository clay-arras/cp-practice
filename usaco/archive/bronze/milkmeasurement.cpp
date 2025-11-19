// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;

struct measurement{
	int day;
	int change;
	string cow;
};

bool compareMeasures(measurement a, measurement b){
	return a.day < b.day;
}

int main() {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

	int n; cin >> n;
	measurement measures[n];

	for(int i=0; i<n; i++) cin >> measures[i].day >>  measures[i].cow >>  measures[i].change;
	
	int ans(0), bessie(7), mildred(7), elsie(7);
	char most[3] = {'b', 'm', 'e'};
	char newMost[3] = {'b', 'm', 'e'};
	int m;
	sort(measures, measures+n, compareMeasures);

	for (int i=0; i<n; i++){
		if (measures[i].cow == "Bessie") bessie += measures[i].change;
		else if (measures[i].cow == "Mildred") mildred += measures[i].change;
		else if (measures[i].cow == "Elsie") elsie += measures[i].change;

		m = max({bessie, mildred, elsie}); 
		if (bessie == m) newMost[0] = 'b';
		else newMost[0] = '.';

		if (mildred == m) newMost[1] = 'm';
		else newMost[1] = '.';

		if (elsie == m) newMost[2] = 'e';
		else newMost[2] = '.';

		if (!equal(most, most+3, newMost)){
			for (int j=0; j<3; j++) most[j] = newMost[j];
			ans++;
		}
	}
	cout << ans << endl;

}
