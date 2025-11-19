// https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int N = (int)s.size();
        unordered_map<char, int> m;
        for (char c : s) 
            m[c]++;

        string ans = "";
        bool ok = false;
        for (int i=0; i<N; i++) {
            if (ok) {
                for (char c='a'; c<='z'; c++) {
                    if (m[c] > 0) {
                        m[c]--;
                        ans.push_back(c);
                        break;
                    }
                }
                
            } else {
                for (char c=target[i]; c<='z'; c++) {
                    if (m[c] > 0) {
                        m[c]--;
                        ans.push_back(c);
                        if (c > target[i])
                            ok = true;
                        break;
                    }
                }
            }
            if ((int)ans.size() != i+1) 
                return "";
        }

        return ans > target ? ans : "";
    }
};