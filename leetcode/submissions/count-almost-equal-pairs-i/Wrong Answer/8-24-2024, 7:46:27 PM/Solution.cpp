// https://leetcode.com/problems/count-almost-equal-pairs-i

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int N = (int)nums.size();
        map<int, int> m;
        int ans = 0;
        for (int i=0; i<N; i++) {
            ans += m[nums[i]];
            string s = "00000" + to_string(nums[i]);
            for (int a=0; a<(int)s.size(); a++) {
                for (int b=4; b<a; b++) {
                    string t = s;
                    swap(t[a], t[b]);
                    m[stoi(t)]++;
                }
            }
            m[nums[i]]++;
        }
        return ans;
    }
};