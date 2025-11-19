// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = (int)matrix.size();

        for (int i=0; i<floor(N*1.0/2); i++) {
            for (int j=0; j<ceil(N*1.0/2); j++) {
                pair<int, int> q2 = {j, N-i-1};
                pair<int, int> q3 = {q2.second, N-q2.first-1};
                pair<int, int> q4 = {q3.second, N-q3.first-1};

                int temp = matrix[i][j];
                matrix[i][j] = matrix[q4.first][q4.second];
                matrix[q4.first][q4.second] = matrix[q3.first][q3.second];
                matrix[q3.first][q3.second] = matrix[q2.first][q2.second];
                matrix[q2.first][q2.second] = temp;
            }
        }
    }
};

// [[3,6,1]
// ,[4,5,2]
// ,[7,8,9]]
