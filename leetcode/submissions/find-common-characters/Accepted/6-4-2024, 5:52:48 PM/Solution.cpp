// https://leetcode.com/problems/find-common-characters

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<map<char, int>> v;
        for (string s : words) {
            map<char, int> m;
            for (char c : s)
                m[c]++;
            v.push_back(m);
        }
        vector<string> ans;
        for (char c='a'; c<='z'; c++) {
            int val = INT_MAX;
            for (auto m : v) 
                val = min(val, m[c]);

            for (int i=0; i<val; i++)
                ans.push_back({c});
        }
        return ans;       
    }
};