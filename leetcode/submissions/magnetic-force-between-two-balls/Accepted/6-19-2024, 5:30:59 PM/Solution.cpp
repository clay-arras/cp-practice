// https://leetcode.com/problems/magnetic-force-between-two-balls

class Solution {
public:
    int lastTrue(int l, int r, function<bool(int)> f) {
        l--;
        for (int diff=r-l; diff>0; diff/=2)
            while (l + diff <= r && f(l + diff))
                l += diff;
        return l;
    }

    const int MX = 1e9;
    int maxDistance(vector<int>& position, int m) {
        int N = (int)position.size();
        sort(position.begin(), position.end());
        
        int ans = lastTrue(1, MX, [&](int k) {
            int cnt = 1;
            int prev = position[0];
            for (int i=1; i<N; i++) {
                if (position[i] - prev >= k) {
                    cnt++;
                    prev = position[i];
                }
            }
            return cnt >= m;
        });
        return ans;
    }
};