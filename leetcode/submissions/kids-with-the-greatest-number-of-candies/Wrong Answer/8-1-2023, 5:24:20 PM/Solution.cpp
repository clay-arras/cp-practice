// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int N = (int)candies.size();
        int mx = -INT_MAX;
        for (auto t : candies) 
            mx = max(mx, t);

        vector<bool> ans(N, false);
        for (int i=0; i<N; i++) {
            if (candies[i] + extraCandies > mx) ans[i] = true;
        }
        return ans;
    }
};