// https://leetcode.com/problems/maximum-population-year

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> m;
        for (auto i : logs) {
            m[i[0]]++;
            m[i[1]]--;
        }

        int cnt = 0, ans = 0, minYear = -1;
        for (auto [k, v] : m) {
            cnt += v;
            if (cnt > ans) {
                ans = cnt;
                minYear = k;
            }
        }
        return minYear;
    }
};