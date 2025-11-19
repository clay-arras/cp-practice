// https://leetcode.com/problems/maximum-total-importance-of-roads

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int, long long> m;
        for (auto v : roads) 
            m[v[0]]++, m[v[1]]++;
        
        priority_queue<int> pq;
        for (auto [k, v] : m) 
            pq.push(v);

        long long sum = 0;
        while (!pq.empty()) {
            long long v = pq.top(); pq.pop();
            sum += v * 1LL * (n--);
        }

        return sum;
    }
};