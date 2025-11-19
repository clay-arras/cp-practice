// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            m[k].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto [k, v] : m)
            ans.push_back(v);
        return ans;
    }
};