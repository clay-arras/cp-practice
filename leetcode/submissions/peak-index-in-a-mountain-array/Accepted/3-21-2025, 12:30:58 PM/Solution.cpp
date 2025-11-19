// https://leetcode.com/problems/peak-index-in-a-mountain-array

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

    int peakIndexInMountainArray(vector<int>& arr) {
        int N = (int)arr.size();
        arr.push_back(-INT_MAX);
        return firstTrue<int>(0, N-1, [&](int i) -> bool {
            return arr[i] > arr[i+1];
        });
    }
};