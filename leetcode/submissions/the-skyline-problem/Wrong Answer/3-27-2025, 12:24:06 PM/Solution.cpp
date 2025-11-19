// https://leetcode.com/problems/the-skyline-problem

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<int>> m;
        for (auto i : buildings) {
            if ((int)m[i[0]].size() == 0) {
                m[i[0]].push_back({0});
            }
            m[i[0]][0] = max(m[i[0]][0], i[2]);
            m[i[1]].push_back(-i[2]);
        }

        map<int, int> rem;
        priority_queue<int> pq;
        vector<vector<int>> ans;

        pq.push(0);
        for (auto [k, v] : m) {
            sort(m[k].begin(), m[k].end());

            if ((int)v.size() == 0) continue;
            if (v[0] > 0) {
                if (v[0] > pq.top()) 
                    ans.push_back({k, v[0]});
                pq.push(v[0]);
            } else {
                if (-v[0] >= pq.top()) {
                    rem[-v[0]]++;
                    while (rem[pq.top()] > 0) {
                        rem[pq.top()]--;
                        pq.pop();
                    }
                    ans.push_back({k, pq.top()});
                } else {
                    rem[-v[0]]++;
                    while (rem[pq.top()] > 0) {
                        rem[pq.top()]--;
                        pq.pop();
                    }
                }
                m[k].erase(m[k].begin());
            }
        }
        return ans;
    }
};