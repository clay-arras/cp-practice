#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct DSU {
	vector<int> e;
    int n;

    void init(int N) {
        n = N;
        e = vector<int>(2*n,-1);
    }

	int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }

	int size(int x) {
        return -e[get(x)];
    }

    // Leader keeps track of enemy
	bool unite(int x, int y) {
		x = get(x), y = get(y);
        if (x == y)
            return 0;

		if (e[x] > e[y])
            swap(x,y);
		e[x] += e[y];
        e[y] = x;

        return 1;
	}
    bool setFrien(int x, int y) {
        x = get(x), y = get(y);
        if (areEnem(x, y))
            return false;

        unite(x, y);
        unite(x+n, y+n);
        return true;
    }
    bool setEnem(int x, int y) {
        x = get(x), y = get(y);
        if (areFrie(x, y))
            return false;

        unite(y, x+n);
        unite(x, y+n);
        return true;
    }
    bool areFrie(int x, int y) {
        x = get(x), y = get(y);
        return (x == y or get(x+n) == get(y+n));
    }
    bool areEnem(int x, int y) {
        x = get(x), y = get(y);
        return (x == get(y+n) or y == get(x+n));
    }

};

void solve() {
    int N; cin >> N;

    int O, X, Y;
    DSU d; d.init(N);

    while (cin >> O >> X >> Y) {
        --X, --Y;
        if (!O and !X and !Y)
            break;

        switch (O) {
            case 1:
                if (!d.setFrien(X, Y)) {
                    cout << -1 << endl;
                }
                break;

            case 2:
                if (!d.setEnem(X, Y)) {
                    cout << -1 << endl;
                }
                break;

            case 3:
                cout << (d.areFrie(X, Y) ? 1 : 0) << endl;
                break;

            case 4:
                cout << (d.areEnem(X, Y) ? 1 : 0) << endl;
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

// If two people are part of the same CC then they are friends.
// For each CC, we maintain a list of enemies. If there is more than one enemy in the list, we should just merge them
// SetFriends should check if the two merged are enemies
// - Else merge them with DSU
// SetEnemies should check if the two merged are friends
// - Else check the list of enemies that that CC has.
//      - If empty, we add the value to the list
//      - Else, we merge the value with the enemy
//
// One DSU should be for friends: if part of CC then friends, otherwise not friends
