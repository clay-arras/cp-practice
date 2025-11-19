// https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int N = (int)damage.size();

        long long sum = 0;
        vector<pair<double, pair<int, int>>> arr(N);
        for (int i=0; i<N; i++) {
            health[i] = ceil(health[i]*1.0/power);
            sum += damage[i];
            arr[i] = {damage[i]*1.0/health[i], {damage[i], health[i]}};
        }
        sort(arr.rbegin(), arr.rend());

        long long ans = 0;
        for (int i=0; i<N; i++) {
            ans += sum * arr[i].second.second;
            sum -= arr[i].second.first;
        }
        return ans;
    }
};