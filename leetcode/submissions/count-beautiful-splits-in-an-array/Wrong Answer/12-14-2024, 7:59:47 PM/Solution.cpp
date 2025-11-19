// https://leetcode.com/problems/count-beautiful-splits-in-an-array

class Solution {
public:
    const static int p = 101;
    const static int mod = 1e9+7;
    int beautifulSplits(vector<int>& nums) {
        if ((int)nums.size() < 3)
            return 0;

        int N = (int)nums.size();
        vector<vector<int>> hash(N, vector<int> (N, -1));
        for (int i=0; i<N; i++) {
            int sum = nums[i];
            long long pow = p;
            for (int j=i; j<N; j++) {
                sum += pow * nums[j];
                pow = (pow * p) % mod;
                sum %= mod;
                hash[i][j] = sum;
            }
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++)
                cout << setw(8) << hash[i][j] << " ";
            cout << endl;
        }

        int ans = 0;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (2*j-i-1 < N && hash[i][j-1] == hash[j][2*j-i-1]) {
                    cout << i << " " << j << endl;
                    cout << (N - (2*j-i)) << endl;
                    ans += (N - (2*j-i));
                    // if () ans++;
                }
            }
        }
        return ans;
    }
};