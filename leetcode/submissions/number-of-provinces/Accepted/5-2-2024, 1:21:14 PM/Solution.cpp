// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    const static int MAXN = 2e2 + 1;
    int visited[MAXN];
    vector<int> adj_list[MAXN];
    void dfs(int s) {
        visited[s] = true;
        for (auto i : adj_list[s]) {
            if (!visited[i]) 
                dfs(i);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = (int)isConnected.size();
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (isConnected[i][j]) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        int count = 0;
        for (int i=0; i<N; i++) {
            if (!visited[i]) {
                count++;
                dfs(i);
            }
        }
        return count;
    }
};