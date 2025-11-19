// https://leetcode.com/problems/path-with-maximum-gold

class Solution {
public:
    int N, M;
    vector<vector<int>> g;

    int search(vector<vector<int>> visited, int i, int j, int maxSum) {
        visited[i][j] = true;
        maxSum += g[i][j];
        int maxCopy = maxSum;

        if (i + 1 < N && !visited[i+1][j] && g[i+1][j])
            maxSum = max(maxSum, search(visited, i+1, j, maxCopy));
        if (j + 1 < M && !visited[i][j+1] && g[i][j+1])
            maxSum = max(maxSum, search(visited, i, j+1, maxCopy));
        if (i - 1 >= 0 && !visited[i-1][j] && g[i-1][j])
            maxSum = max(maxSum, search(visited, i-1, j, maxCopy));
        if (j - 1 >= 0 && !visited[i][j-1] && g[i][j-1])
            maxSum = max(maxSum, search(visited, i, j-1, maxCopy));
        return maxSum;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        N = (int)grid.size(), M = (int)grid[0].size();
        g = grid;
        vector<vector<int>> visited(N, vector<int> (M, 0));

        int ans = 0;
        for (int i=0; i<N; i++) 
            for (int j=0; j<M; j++) 
                if (g[i][j])
                    ans = max(ans, search(visited, i, j, 0));
                    
        return ans;
    }
};