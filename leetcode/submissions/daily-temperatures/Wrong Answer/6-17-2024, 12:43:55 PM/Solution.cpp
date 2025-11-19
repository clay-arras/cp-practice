// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = (int)temperatures.size();
        stack<pair<int, int>> s;
        vector<int> ans(N, 0);

        for (int i=0; i<N; i++) {
            while (!s.empty() && s.top().first <= temperatures[i]) {
                pair<int, int> x = s.top();
                ans[x.second] = i - x.second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }

        return ans;
    }
};