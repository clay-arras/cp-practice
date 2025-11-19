// https://leetcode.com/problems/evaluate-division

class Solution {
public:
    map<string, vector<pair<string, double>>> adj_list;
    map<string, bool> visited;
    string en; double sol;


    void dfs(string x, double back) {
        visited[x] = true;
        if (x == en) sol = back;
        for (pair<string, double> i : adj_list[x]) {
            if (!visited[i.first]) 
                dfs(i.first, back * i.second);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int N = (int)values.size();
        map<string, bool> def;
        for (int i=0; i<N; i++) {
            adj_list[equations[i][0]].push_back({equations[i][1], 1.0/values[i]});
            adj_list[equations[i][1]].push_back({equations[i][0], values[i]});
            def[equations[i][0]] = true;
            def[equations[i][1]] = true;
        }

        vector<double> ans;
        for (auto i : queries) {
            visited.clear();
            en = i[0], sol = -1;
            if (def[i[1]] && def[i[0]])
                dfs(i[1], 1.0);
            ans.push_back(sol);
        }
        return ans;
    }
};