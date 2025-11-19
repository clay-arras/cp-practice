// https://leetcode.com/problems/minimum-time-to-repair-cars

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

    long long repairCars(vector<int>& ranks, int cars) {
        int N = (int)ranks.size();
        return firstTrue<long long> (0, 1e18, [&](long long m) {
            long long c = 0;
            for (int i=0; i<N; i++) 
                c += sqrt(m*1.0/ranks[i]);
            return c >= cars;
        });
    }
};