// https://leetcode.com/problems/score-after-flipping-matrix

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int N = (int)grid.size(), M = (int)grid[0].size();
        
        for (auto i : grid) {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
        cout << endl;

        for (int j=0; j<N; j++)
            if (grid[j][0] == 0)
                for (int i=0; i<M; i++) 
                    grid[j][i] = !grid[j][i];

        for (auto i : grid) {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
        
        int ans = 0;
        for (int i=0; i<M; i++) {
            int count = 0;
            for (int j=0; j<N; j++) 
                count += grid[j][i];
            ans += (1 << (M - i - 1)) * max(count, N - count);
        }
        return ans;
    }
};