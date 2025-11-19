// https://leetcode.com/problems/path-with-maximum-gold

class Solution {
public:
    int N, M;
    int search(vector<bitset<15>>& visited, int i, int j, int maxSum, vector<vector<int>>& g) {
        visited[i][j] = true;
        maxSum += g[i][j];
        int maxCopy = maxSum;

        // for (auto i : visited) {
        //     for (int j=0; j<15; j++)
        //         cout << i[j] << " ";
        //     cout << endl;
        // }
        // cout << endl;

        if (i + 1 < N && !visited[i+1][j] && g[i+1][j])
            maxSum = max(maxSum, search(visited, i+1, j, maxCopy, g));
        if (j + 1 < M && !visited[i][j+1] && g[i][j+1])
            maxSum = max(maxSum, search(visited, i, j+1, maxCopy, g));
        if (i - 1 >= 0 && !visited[i-1][j] && g[i-1][j])
            maxSum = max(maxSum, search(visited, i-1, j, maxCopy, g));
        if (j - 1 >= 0 && !visited[i][j-1] && g[i][j-1])
            maxSum = max(maxSum, search(visited, i, j-1, maxCopy, g));

        visited[i][j] = false;
        return maxSum;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        N = (int)grid.size(), M = (int)grid[0].size();
        vector<bitset<15>> visited(N);

        int ans = 0;
        for (int i=0; i<N; i++) 
            for (int j=0; j<M; j++) 
                if (grid[i][j])
                    ans = max(ans, search(visited, i, j, 0, grid));

        return ans;
    }
};