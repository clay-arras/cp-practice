// https://leetcode.com/problems/filling-bookcase-shelves

class Solution {
public:
    const static int MXV = 1e3+1;
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        books.insert(books.begin(), {0, 0});
        int N = (int)books.size();
        vector<int> dp(N, 1e9);

        dp[0] = 0;
        for (int i=1; i<N; i++) {
            int sum = 0, mx = 0;
            for (int j=i; sum<=shelfWidth && j>=1; j--) {
                sum += books[j][0];
                if (sum > shelfWidth)
                    break;
                mx = max(mx, books[j][1]);
                dp[i] = min(dp[i], dp[j-1] + mx);
            }
        }
        return dp[N-1];
    }
};
// intuition, at each book we have two choices: start a new shelf, or keep on this shelf --> 2^N to polynomial pattern