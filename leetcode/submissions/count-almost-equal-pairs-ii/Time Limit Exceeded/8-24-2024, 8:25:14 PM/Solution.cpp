// https://leetcode.com/problems/count-almost-equal-pairs-ii

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int N = (int)nums.size();
        unordered_map<long long, int> m;
        int ans = 0;
        for (int i=0; i<N; i++) {
            ans += m[1LL*nums[i]];
            string s = "000000" + to_string(nums[i]);
            unordered_map<long long, int> mt;
            for (int a=0; a<(int)s.size(); a++) {
                for (int b=0; b<(int)s.size(); b++) {
                    for (int c=0; c<(int)s.size(); c++) {
                        for (int d=0; d<(int)s.size(); d++) {
                            string t = s;
                            swap(t[a], t[b]);
                            swap(t[c], t[d]);
                            if (!mt[stoll(t, nullptr, 10)]) {
                                m[stoll(t, nullptr, 10)]++;
                                mt[stoll(t, nullptr, 10)]++;
                            }
                        }
                    }
                }
            }
            // m[nums[i]]++;
        }
        return ans;
    }
};