// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks

class Solution {
public:
    const static int MX = 2e9+1;
    int firstTrue(int l, int r, function<bool(int)> f) {
        r++;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int N = (int)tasks.size();
        vector<pair<int, pair<int, int>>> t;
        for (auto i : tasks)
            t.push_back({-i[1] + i[0], {-i[1], i[0]}});
        sort(t.begin(), t.end());
        // for (auto i : t)
        //     cout << i.first << " " << i.second << endl;

        const auto ok = [&](int k) {
            for (int i=0; i<N; i++) {
                if (-t[i].second.first <= k) 
                    k -= t[i].second.second;
                else return false;
            }
            return true;
        };

        return firstTrue(0, MX, ok);
    }
};