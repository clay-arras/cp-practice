// https://leetcode.com/problems/count-pairs-with-xor-in-a-range

class Solution {
public:
    vector<int> n;
    const static int MXV = 2e4;
    int xorLessThanK(int k) {
        int N = (int)n.size();

        vector<pair<int, int>> x;     
        for (int i=1; i<=MXV; i++) {
            x.push_back({i ^ k, i});
        }
        sort(x.begin(), x.end());

        vector<int> v(MXV+1, 0);
        map<int, int> m;
        for (int i : n)
            m[i]++;

        for (int i=1; i<=MXV; i++) {
            v[i] += v[i-1];
            v[i] += m[x[i-1].second];
        }

        int ans = 0;
        for (int i=0; i<N; i++) {
            ans += v[n[i]] - 1;
        }
        return ans;
    }
    
    int countPairs(vector<int>& nums, int low, int high) {
        sort(nums.begin(), nums.end());
        n = nums;
        return xorLessThanK(high) - xorLessThanK(low - 1); 
    }
};