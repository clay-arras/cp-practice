// https://leetcode.com/problems/find-all-groups-of-farmland

class Solution {
public:
    map<pair<int, int>, pair<int, int>> ans;
    vector<vector<bool>> visited;
    int N, M; 
    void dfs(int i, int j, vector<vector<int>> land, pair<int, int> start) {
        if (visited[i][j] || land[i][j] != 1) {
            return;
        }
        visited[i][j] = true;

        if (i + 1 < N && land[i+1][j] == 1) {
            dfs(i + 1, j, land, start);
        }
        if (j + 1 < M && land[i][j+1] == 1) {
            dfs(i, j + 1, land, start);
        }
        if (i + 1 < N && land[i+1][j] != 1 && j + 1 < M && land[i][j+1] != 1) {
            ans[start] = {i, j};
        }
        if (i + 1 >= N && j + 1 >= M) {
            ans[start] = {i, j};
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // iterate through top to bottom left to right
        N = (int)land.size();
        M = (int)land[0].size();
        visited = vector<vector<bool>> (N, vector<bool>(M, false));

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (land[i][j] == 1 && !visited[i][j])
                    dfs(i, j, land, {i, j});
            }
        }
        vector<vector<int>> ret;
        for (auto [k, v] : ans) {
            vector<int> tmp;
            tmp.push_back(k.first);
            tmp.push_back(k.second);
            tmp.push_back(v.first);
            tmp.push_back(v.second);
            ret.push_back(tmp);
        }

        return ret;
        // convert back to vectors
    }
};