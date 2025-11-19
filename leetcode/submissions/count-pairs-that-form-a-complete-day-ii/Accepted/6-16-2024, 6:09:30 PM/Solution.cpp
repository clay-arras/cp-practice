// https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii

class Solution {
public:
    const static int MOD = 24;
    long long countCompleteDayPairs(vector<int>& hours) {
        map<int, long long> m;
        long long ans = 0;
        for (int i=0; i<(int)hours.size(); i++) {
            ans += m[(MOD-hours[i]%MOD)%MOD];
            m[hours[i]%MOD]++;
        }
        return ans;
    }
};