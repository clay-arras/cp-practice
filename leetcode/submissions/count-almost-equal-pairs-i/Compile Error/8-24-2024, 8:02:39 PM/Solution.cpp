// https://leetcode.com/problems/count-almost-equal-pairs-i

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int N = (int)nums.size();
        map<long long, int> m;
        int ans = 0;
        for (int i=0; i<N; i++) {
            // cout << nums[i] << " " << m[nums[i]] << endl;
            ans += m[1LL*nums[i]];
            string s = "00000" + to_string(nums[i]);
            for (int a=0; a<(int)s.size(); a++) {
                for (int b=4; b<a; b++) {
                    string t = s;
                    swap(t[a], t[b]);
                    if (strtoll(t) != strtoll(s))
                        m[strtoll(t)]++;
                }
            }
            m[strtoll(s)]++;
        }
        return ans;
    }
};