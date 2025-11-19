// https://leetcode.com/problems/count-almost-equal-pairs-i

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int N = (int)nums.size();
        map<long long, int> m;
        int ans = 0;
        for (int i=0; i<N; i++) {
            ans += m[1LL*nums[i]];
            string s = "000000" + to_string(nums[i]);
            for (int a=0; a<(int)s.size(); a++) {
                for (int b=0; b<a; b++) {
                    string t = s;
                    swap(t[a], t[b]);
                    if (stoll(t, nullptr, 10) != stoll(s, nullptr, 10))
                        m[stoll(t, nullptr, 10)]++;
                }
            }
            m[nums[i]]++;
        }
        return ans;
    }
};