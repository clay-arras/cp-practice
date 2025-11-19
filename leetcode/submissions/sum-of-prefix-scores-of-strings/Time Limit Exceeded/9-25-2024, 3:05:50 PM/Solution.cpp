// https://leetcode.com/problems/sum-of-prefix-scores-of-strings

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        map<string, int> m;
        int N = (int)words.size();
        for (int i=0; i<N; i++) {
            for (int j=1; j<=(int)words[i].size(); j++) {
                m[words[i].substr(0, j)]++;
            }
        }
        vector<int> ans;
        for (int i=0; i<N; i++) {
            int sum = 0;
            for (int j=1; j<=(int)words[i].size(); j++) {
                sum += m[words[i].substr(0, j)];
            }
            ans.push_back(sum);
        }


        return ans;
    }
};