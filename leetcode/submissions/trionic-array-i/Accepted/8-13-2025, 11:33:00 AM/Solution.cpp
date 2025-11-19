// https://leetcode.com/problems/trionic-array-i

class Solution {
public:
    vector<int> arr;
    
    bool check_inc(int l, int r) {
        bool ok = true;
        for (int i=l+1; i<=r; i++) {
            ok &= (arr[i] > arr[i-1]);
        }
        return ok;
    }
    bool check_dec(int l, int r) {
        bool ok = true;
        for (int i=l+1; i<=r; i++) {
            ok &= (arr[i] < arr[i-1]);
        }
        return ok;
    }
    
    bool isTrionic(vector<int>& nums) {
        int N = (int)nums.size();
        arr = nums;
        bool ok = false;
        for (int l=1; l<N-1; l++) {
            for (int r=l+1; r<N-1; r++) {
                ok |= check_inc(0, l) && check_dec(l, r) && check_inc(r, N-1);
            }
        }
        return ok;
    }
};