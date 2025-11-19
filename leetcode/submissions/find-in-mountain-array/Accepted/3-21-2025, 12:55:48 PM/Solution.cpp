// https://leetcode.com/problems/find-in-mountain-array

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    template<class T>
    T firstTrue(T l, T r, function<bool(T)> f) {
        r++;
        while (l < r) {
            T mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int N = mountainArr.length();
        
        int piv = firstTrue<int>(0, N-1, [&](int i) -> bool {
            if (i == N-1)
                return true;
            return mountainArr.get(i) > mountainArr.get(i+1);
        });
        
        int l = firstTrue<int>(0, piv, [&](int i) -> bool {
            return mountainArr.get(i) >= target;
        });
        int r = firstTrue<int>(piv, N-1, [&](int i) -> bool {
            return mountainArr.get(i) <= target;
        });
        
        if ((l >= 0 && l < N) && mountainArr.get(l) == target)
            return l;
        if ((r >= 0 && r < N) && mountainArr.get(r) == target)
            return r;
        return -1;
    }
};