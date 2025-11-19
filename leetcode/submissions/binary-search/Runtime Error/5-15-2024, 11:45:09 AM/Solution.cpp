// https://leetcode.com/problems/binary-search

class Solution {
public:

    template<class T>
    T lastTrue(T lo, T hi, function<bool(T)> f) {
        lo--;
        for (T dif=hi-lo; dif>0; dif/=2) {
            while (lo + dif <= hi && f(lo + dif)) { lo += dif; }
        }
        return lo;
    }

    // template<class T>
    // T firstTrue(T lo, T hi, function<bool(T)> f) {
    //     hi++;
    //     while (lo < hi) {
    //         T mid = lo + (hi - lo) / 2;
    //         if (f(mid)) hi = mid;
    //         else lo = mid + 1;
    //     }
    //     return lo;
    // }

    int search(vector<int>& nums, int target) {
        int N = (int)nums.size();
        function<bool(int)> ok = [&](int k) -> bool {
            return nums[k] <= target;
        };

        int val = lastTrue(0, N-1, ok);
        return (nums[val] == target ? val : -1);
    }
};