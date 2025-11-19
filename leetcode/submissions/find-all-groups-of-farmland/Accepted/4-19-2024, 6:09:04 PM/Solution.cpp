// https://leetcode.com/problems/find-all-groups-of-farmland

class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> ret;
    vector<vector<int>> arr;
    
    int N, M; 
    void dfs(int i, int j, pair<int, int> start) {
        if (visited[i][j] || arr[i][j] != 1) 
            return;
        visited[i][j] = true;

        if (i + 1 < N && arr[i+1][j] == 1) 
            dfs(i + 1, j, start);
        if (j + 1 < M && arr[i][j+1] == 1) 
            dfs(i, j + 1, start);

        bool iCond = (i + 1 < N && arr[i+1][j] != 1) || (i + 1 >= N);
        bool jCond = (j + 1 < M && arr[i][j+1] != 1) || (j + 1 >= M);
        if (iCond && jCond) {
            ret.push_back({start.first, start.second, i, j});
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        N = (int)land.size();
        M = (int)land[0].size();
        visited = vector<vector<bool>> (N, vector<bool>(M, false));
        arr = land;

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (land[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j, {i, j});
                }
            }
        }

        return ret;
    }
};