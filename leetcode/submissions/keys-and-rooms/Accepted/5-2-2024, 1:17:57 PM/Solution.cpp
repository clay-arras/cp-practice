// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> adj_list;
    int count = 0;
    void dfs(int s) {
        visited[s] = true;
        count++;
        for (auto i : adj_list[s]) {
            if (!visited[i])
                dfs(i);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = (int)rooms.size();
        visited = vector<bool> (N, false);
        adj_list = rooms;
        dfs(0);
        return (count == N);
    }
};