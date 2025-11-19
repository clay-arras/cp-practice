#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, X; cin >> N >> X;

    vector<int> A(N);
    for (int& t : A)
        cin >> t;

    // Not doing the big small thing for now

    vector<int> val(X+1, 0);
    for (int i=1; i<N; i++) {
        int a = A[i], b = A[i-1];
        if (a > b)
            swap(a, b);
        if (a > X)
            continue;
        val[a] = max(val[a], b-a);
    }

    set<pair<int, int>> L, R;
    for (int i=1; i<N; i++) {
        L.insert({-(A[i] + A[i-1]), abs(A[i] - A[i-1])});
        R.insert({A[i] + A[i-1], abs(A[i] - A[i-1])});
    }

    int ans = 0;
    for (int i=1; i<N; i++) {
        ans += abs(A[i] - A[i-1]);
    }
    cout << ans << endl;
    for (int i=1; i<=X; i++) {
        if (i+val[i] > X)
            break;
        i += val[i];

        auto lVal = *L.lower_bound({-2*i, 0});
        auto rVal = *R.lower_bound({2*i, 0});

        int lDist = abs(lVal.first + 2*i);
        int rDist = abs(rVal.first - 2*i);
        if (lDist < rDist) {
            ans += abs(lDist - lVal.second);
        } else {
            ans += abs(rDist - rVal.second);
        }

    }
    cout << ans << endl;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*

brute force    constructive algorithms    greedy    *1600

Observation:
- If the values are inserted between two values in the same range, then the extra cost is zero
- It is always worthwhile to insert if there is space
- With outliers, the best optionis to get the average distance nearest

- Calculate the existing difference values
- It is always worthwhile to insert if there is space
- Otherwise, we have to calculate the least distance possible


We have N-1 Ranges
What if we eliminate ranges of the X value
All elements are shadowed by peaks

Big Small Big Small
6 1 5 7 3 3 9 10 10 1
6 1 7 3 10 1

- x_1 - x_2
- abs(y-x_1) + abs(y-x_2)

If Y is greater than both:
- 2*y - (x_1+x_2)
If Y is less than both:
- (x_1+x_2) - 2*y

Difference change is the same
We want the smallest average distance between the two
Average all the ranges


Next Question: How do we find the values not covered by the ranges
At the beginning of the thing, we write the length
We can just skip the next range

CASES:
- Seperate case for only one value (N = 1)
- What if the best solution is to put it up against the edge

 */
