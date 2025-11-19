// https://leetcode.com/problems/couples-holding-hands

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        const auto cmpl = [&](int k){
            if (k % 2 == 0)
                return k+1;
            else return k-1;
        };
        map<int, int> m;
        int N = (int)row.size();

        for (int i=0; i<N; i++) {
            auto it = find(row.begin(), row.end(), cmpl(row[i]));
            m[i] = cmpl(it - row.begin());
            assert(it != row.end());
        }

        int ans = 0;
        vector<bool> visited(N, false);
        for (int i=0; i<N; i++) {
            if (!visited[i]) {
                int sum = 0;
                int ptr = i;
                while (m[ptr] != i) {
                    ptr = m[ptr];
                    visited[ptr] = true;
                    sum++;
                }
                ans += sum;
            }
        }

        return ans / 2;
    }
};