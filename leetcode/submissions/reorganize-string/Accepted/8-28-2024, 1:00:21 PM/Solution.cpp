// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        for (char c : s)
            m[c]++;
        
        for (auto [k, v] : m)
            pq.push({v, k});

        string ans = "";
        while (!pq.empty()) {
            if ((int)ans.size() && pq.top().second == ans[(int)ans.size()-1]) {
                pair<int, char> y = pq.top();
                pq.pop();
                if (pq.empty())
                    return "";

                pair<int, char> x = pq.top();
                pq.pop();
                ans.push_back(x.second);
                if (x.first-1)
                    pq.push({x.first-1, x.second});
                pq.push({y.first, y.second});
            } else {
                pair<int, char> x = pq.top();
                pq.pop();
                ans.push_back(x.second);
                if (x.first-1)
                    pq.push({x.first-1, x.second});
            }
        }

        return ans;
    }
};