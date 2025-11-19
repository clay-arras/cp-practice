// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, pair<int, int>>> arr;
        int N = (int)quality.size();
        for (int i=0; i<N; i++) 
            arr.push_back({wage[i]*1.0/quality[i], {wage[i], quality[i]}});
        
        sort(arr.begin(), arr.end());
        priority_queue<int> pq;
        double ans = INT_MAX;
        int sum = 0;
        for (int i=0; i<N; i++) {
            pq.push(arr[i].second.second);
            sum += arr[i].second.second;
            if ((int)pq.size() >= k) {
                int t = pq.top();
                ans = min(ans, arr[i].first * sum);
                pq.pop();
                sum -= t;
            }
        }
        return ans;
    }
};