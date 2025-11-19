// https://leetcode.com/problems/number-of-zigzag-arrays-i

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9+7;
        int d = r - l + 1;

        vector<int> up(d, 0), dw(d, 0);
        for (int j=0; j<d; j++) {
            dw[j] = d-j-1;
            up[j] = j;
        }

        for (int i=0; i<n-2; i++) {
            vector<int> nup(d, 0), ndw(d, 0);
            int roll = 0;
            for (int k=0; k<d; k++) {
                nup[k] = roll;
                roll += dw[k];
            }

            roll = 0;
            for (int k=d-1; k>=0; k--) {
                ndw[k] = roll;
                roll += up[k];
            }

            for (int i : dw)
                cout << i << " ";
            cout << endl;
            for (int i : up)
                cout << i << " ";
            cout << endl;
            cout << endl;
            
            dw = ndw;
            up = nup;
        }

        long long sum = 0;
        for (int j=0; j<d; j++)
            sum += (dw[j] + up[j]) % MOD;
        return sum % MOD;
    }
};