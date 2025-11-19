// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    string remChar(const string& s, int i) {
        return s.substr(0, i) + s.substr(i+1, (int)s.size());
    }

    int longestStrChain(vector<string>& words) {
        int N = (int)words.size();
        int ans = 1;
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return (int)a.size() < (int)b.size();
        });

        unordered_map<string, int> m;
        for (int i=N-1; i>=0; i--) {
            int curr = m[words[i]] + 1;
            ans = max(ans, curr);
            for (int j=0; j<(int)words[i].size(); j++) 
                m[remChar(words[i], j)] = max(m[remChar(words[i], j)], curr);
        }
        return ans;
    }
};