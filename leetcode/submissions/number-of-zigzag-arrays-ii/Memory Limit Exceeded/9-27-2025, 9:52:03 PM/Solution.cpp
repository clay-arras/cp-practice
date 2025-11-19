// https://leetcode.com/problems/number-of-zigzag-arrays-ii

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9+7;
        int d = r - l + 1;

        vector<long long> up(d, 0), dw(d, 0);
        for (int j=0; j<d; j++) {
            dw[j] = d-j-1;
            up[j] = j;
        }

        vector<long long> nup(d, 0), ndw(d, 0);
        for (int i=0; i<n-2; i++) {
            nup = vector<long long>(d, 0);
            ndw = vector<long long>(d, 0);
            long long roll = 0;
            for (int k=0; k<d; k++) {
                nup[k] = roll;
                roll += dw[k] % MOD;
            }

            roll = 0;
            for (int k=d-1; k>=0; k--) {
                ndw[k] = roll;
                roll += up[k] % MOD;
            }
            dw.swap(ndw);
            up.swap(nup);

            ndw.clear();
            nup.clear();
        }

        long long sum = 0;
        for (int j=0; j<d; j++)
            sum += (dw[j] + up[j]) % MOD;
        return sum % MOD;
    }
};