// https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj_list1;
    unordered_map<string, vector<pair<string, double>>> adj_list2;
    
    unordered_map<string, double> Dijkstras(string src, unordered_map<string, vector<pair<string, double>>> &adj_list) {
        unordered_map<string, double> dist;
        priority_queue<pair<double, string>> q;
        for (auto [k, v] : adj_list1)
            dist[k] = 0;
        for (auto [k, v] : adj_list2)
            dist[k] = 0;
        
        dist[src] = 1.0;
        q.push({1.0, src});
        
        while (q.size()) {
            double x = q.top().first;
            string u = q.top().second;
            
            q.pop();
            // if (x != dist[u]) continue;
            for (auto i : adj_list[u]) {
                if (x * i.second > dist[i.first]) {
                    dist[i.first] = x * i.second;
                    q.push({dist[i.first], i.first});
                }
            }
        }
        return dist;
    }


    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        int N1 = (int)pairs1.size();
        int N2 = (int)pairs2.size();

        for (int i=0; i<N1; i++) {
            adj_list1[pairs1[i][0]].push_back({pairs1[i][1], rates1[i]});
            adj_list1[pairs1[i][1]].push_back({pairs1[i][0], 1.0/rates1[i]});
        }
        for (int i=0; i<N2; i++) {
            adj_list2[pairs2[i][0]].push_back({pairs2[i][1], 1.0/rates2[i]});
            adj_list2[pairs2[i][1]].push_back({pairs2[i][0], rates2[i]});
        }
        unordered_map<string, double> dist1 = Dijkstras(initialCurrency, adj_list1);
        unordered_map<string, double> dist2 = Dijkstras(initialCurrency, adj_list2);

        double ans = 1;
        for (auto [k, v] : adj_list1) {
            if (dist2[k])
                ans = max(ans, dist1[k]*dist2[k]);
        }
        for (auto [k, v] : adj_list2) {
            if (dist2[k])
                ans = max(ans, dist1[k]*dist2[k]);
        }

        return ans;
    }
};