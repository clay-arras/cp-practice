// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    const static int MX = 1e9 + 1;

    int firstTrue(int l, int r, function<bool(int)> f) {
        r++;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = firstTrue(1, MX-1, [&](int j) {
            int nums = 0, cnt = 1;
            for (int i=0; i<(int)bloomDay.size(); i++) {
                if (bloomDay[i] > j || cnt >= k) {
                    nums += (cnt >= k);
                    cnt = 0;
                }
                cnt += (bloomDay[i] <= j);
            }
            return nums >= m;
        });
        return (ans == MX ? -1 : ans);
    }
};