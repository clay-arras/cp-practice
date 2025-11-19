// https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        map<int, int> m;
        int N = (int)hours.size();
        int ans = 0;
        for (int i=0; i<N; i++) {
            ans += m[(24-hours[i]%24)%24];
            m[hours[i]%24]++;
        }
        return ans;
    }
};