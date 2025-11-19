// https://leetcode.com/problems/time-needed-to-inform-all-employees

class Solution {
public:
    const static int MX = 1e5+1;
    vector<int> adj_list[MX];
    vector<bool> visited;
    vector<int> t;
    
    int dfs(int i) {
        visited[i] = true;
        
        int ret = 0;
        for (int x : adj_list[i]) {
            if (!visited[x])
                ret = max(ret, dfs(x));
        }
        return ret + t[i];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        t = informTime;
        for (int i=0; i<n; i++)
            if (manager[i] != -1)
                adj_list[manager[i]].push_back(i);
        
        visited = vector<bool> (n, false);
        return dfs(headID);
    }
};