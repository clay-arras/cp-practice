// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    const int MX = 1e4;
    int subarraysDivByK(vector<int>& nums, int k) {
        int N = (int)nums.size();
        vector<int> pref(N+1, 0);
        for (int i=0; i<N; i++) 
            pref[i+1] += pref[i] + nums[i];

        int ans = 0;
        map<int, int> m;
        for (int i=1; i<=N; i++) {
            m[(pref[i-1]+MX*k)%k]++;
            if (m[(pref[i]+MX*k)%k]) 
                ans += m[(pref[i]+MX*k)%k];
        }

        for (auto i : pref)
            cout << i << " ";
        cout << endl;

        for (auto [k, v] : m)
            cout << k << " " << v << endl;


        return ans;        
    }
};