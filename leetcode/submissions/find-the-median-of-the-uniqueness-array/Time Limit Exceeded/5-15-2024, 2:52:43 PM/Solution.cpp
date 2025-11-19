// https://leetcode.com/problems/find-the-median-of-the-uniqueness-array

class Solution {
public:

    int N;
    vector<int> arr;

    int lastTrue(int l, int r) {
        l--;
        for (int diff=r-l; diff>0; diff/=2)
            while (l+diff <= r && ok(l+diff))
                l += diff;
        return l;
    }

    bool ok(int k) {
        map<int, int> less;
        long long lans = 0;
        int r=0, l=0, count=0;
        for (; r<N && l<=r; r++) {
            if (less[arr[r]] == 0) count++;
            less[arr[r]]++;
            while (l<r && count >= k) {
                if (less[arr[l]] == 1) 
                    count--;
                less[arr[l]]--;
                l++;
            }
            if (count < k)
                lans += r-l+1;
        }

        map<int, int> great;
        long long rans = 0;
        r=0, l=0, count=0;
        for (; r<=N && l<=r && l<N; l++) {
            while (r<N && count < k) {
                if (great[arr[r]] == 0) 
                    count++;
                great[arr[r]]++;
                r++;
            }
            if (count >= k)
                rans += N-r+1;
            if (great[arr[l]] == 1) count--;
            great[arr[l]]--;
        }

        return lans < rans;
    }

    int medianOfUniquenessArray(vector<int>& nums) {
        N = (int)nums.size();
        arr = nums;
        
        return lastTrue(0, N);
    }
};