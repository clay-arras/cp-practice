// https://leetcode.com/problems/k-th-nearest-obstacle-queries

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type,
      less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans;
        oset<pair<int, int>> s;
        for (int i=0; i<(int)queries.size(); i++) {
            s.insert({abs(queries[i][0]) + abs(queries[i][1]), i});
            auto it = s.find_by_order(k-1);
            if (it != s.end()) {
                ans.push_back(it->first);
            } else ans.push_back(-1);
        }

        return ans;
    }
};