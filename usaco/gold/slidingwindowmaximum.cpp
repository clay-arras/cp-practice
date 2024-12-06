#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    set<pair<int, int>> s;

    for (int i=0; i<k; i++)
        s.insert({-nums[i], i});

    int N = (int)nums.size();
    for (int i=k; i<N; i++) {
        ans.push_back(-(*s.begin()).first);
        s.erase({-nums[i-k], i-k});
        s.insert({-nums[i], i});
    }
    ans.push_back(-(*s.begin()).first);
    return ans;
}

void solve() {
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    int k = 4;

    cout << maxSlidingWindow(nums, k) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

// Case 1: the maximum value is the one on the very left
// - Result: we take the maximum of the values in the array (mid) and the max of the new value
// Case 2: the maximum value is in the middle
// - Result: we return the maximum value
// Case 3: the maximum value is the new value
// - Result we store
//
// 1. Take the index of all the values
// 2. When we find maximum value we also store the index and make a priority queue
//  - Or just take a set and we can erase the value
