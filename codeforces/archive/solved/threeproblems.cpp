// apparently you could only use koltin for this problem so i never submitted it

#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

int main() {
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif
	int N; cin >> N;

	set<int> num;
	map<int, int> m;

	int a;
	for (int i=0; i<N; i++){
		cin >> a;
		num.insert(a);
		if (num.count(a)){
			m.insert(make_pair(a, i+1));
		}
	}

	int count=0;
	if (num.size() < 3){
		cout << "-1 -1 -1" << endl;
	}else {
		for (auto i=num.begin(); i!=num.end(); i++){
			if (count == 3) break;
			cout << m[*i] << " ";
			count++;
		}
	}

}