// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    int firstTrue(int l, int r, function<bool(int)> f) {
        r++;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    const int MX = 1e9;
    int minEatingSpeed(vector<int>& piles, int h) {
        int N = (int)piles.size();

        auto fn = [&](int K) {
            int totalHours = 0;
            for (int i : piles)
                totalHours += (int)ceil(i*1.0/K); 
            return totalHours <= h;
        };

        return firstTrue(1, 1e5, fn);
    }
};