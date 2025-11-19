// https://leetcode.com/problems/binary-search

class Solution {
public:

    // template<class T>
    // T lastTrue(T l, T r, function<bool(T)> f) {
    //     l--;
    //     for (T diff=r-l; diff>0; diff/=2) 
    //         while (l + diff <= r && f(l + diff))  
    //             l += diff; 
    //     return l;
    // }

    template<class T>
    T firstTrue(T l, T r, function<bool(T)> f) {
        // r++;
        for (r++ ; l < r; ) {
            T mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int search(vector<int>& nums, int target) {
        int N = (int)nums.size();

        // function<bool(int)> ok = [&](int k) -> bool {
        //     if (k >= 0 && k < N)
        //         return nums[k] <= target;
        //     return (k >= 0);
        // };

        function<bool(int)> ok = [&](int k) {
            if (k >= 0 && k < N)
                return nums[k] >= target;
            return (k < N);
        };

        int val = firstTrue(0, N-1, ok);
        return (val >= 0 && val < N && nums[val] == target ? val : -1);
    }
};