// https://leetcode.com/problems/increasing-triplet-subsequence

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type,
      less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        oset<int> one, two;

        bool ans = false;
        int N = (int)nums.size();
        for (int i=0; i<N; i++) {
            if (one.order_of_key(nums[i]) > 0) {
                two.insert(nums[i]);
            }
            if (two.order_of_key(nums[i]) > 0) {
                ans |= true;
            }
            one.insert(nums[i]);
        }
        
        return ans;
    }
};