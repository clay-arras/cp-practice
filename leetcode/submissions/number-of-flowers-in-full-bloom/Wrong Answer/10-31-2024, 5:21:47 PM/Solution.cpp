// https://leetcode.com/problems/number-of-flowers-in-full-bloom

class Solution {
public:
    int lastTrue(int l, int r, function<bool(int)> f) {
        l--;
        for (int diff=r-l; diff>0; diff/=2)
            while (l + diff <= r && f(l + diff))
                l += diff;
        return l;
    }
    int firstTrue(int l, int r, function<bool(int)> f) {
        r++;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }


    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int N = (int)people.size();
        vector<pair<int, int>> arr(N);
        for (int i=0; i<N; i++)
            arr[i] = {people[i], i};
        sort(arr.begin(), arr.end());

        vector<int> diff(N+1);
        for (vector<int> i : flowers) {
            int lower_bound = firstTrue(0, N-1, [&](int k) {
                return arr[k].first >= i[0];
            });
            int upper_bound = lastTrue(0, N-1, [&](int k) {
                return arr[k].first <= i[1];
            });
            lower_bound = max(min(lower_bound, N-1), 0);
            upper_bound = max(min(upper_bound, N-1), 0);

            diff[lower_bound]++;
            diff[upper_bound+1]--;
        }
        vector<int> ans(N);
        ans[0] = diff[0];
        for (int i=1; i<N; i++) 
            ans[i] = diff[i] + ans[i-1];

        vector<int> ret(N);
        for (int i=0; i<N; i++) {
            ret[arr[i].second] = ans[i];
        }

        return ret;
    }

    // take people, sort index
    // for each interval binary search over people + get min and max index
    // use difference array to reconstruct
    // then resort everything
};