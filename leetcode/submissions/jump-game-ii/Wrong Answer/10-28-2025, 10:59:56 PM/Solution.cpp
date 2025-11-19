// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int N = (int)nums.size();    

        int ans = 0;
        for (int i=0; i<N-1; ) {
            pair<int, int> nx = {i+1+nums[i+1], i+1};
            for (int j=1; i+j<N && j<=nums[i]; j++)
                nx = max(nx, {i+j+nums[i+j], i+j});
            i = nx.second;
            if (i < N)
                ans++;
        }
        return ans;
    }
};