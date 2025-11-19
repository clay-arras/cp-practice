// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int N = (int)temperatures.size();
        vector<int> arr(N, 0);
        for (int i=0; i<N; i++) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                arr[s.top()] = i - s.top();
                s.pop();
            }
            // if (s.length()) {

            // }
            s.push(i);
        }
        return arr;
    }
};