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
        // sort(piles.begin(), piles.end());
        return firstTrue(1, MX, [&](int k) {
            int sum = 0;
            for (int i : piles) 
                sum += ceil(i*1.0/k);
            return sum <= h;
        });
    }
};