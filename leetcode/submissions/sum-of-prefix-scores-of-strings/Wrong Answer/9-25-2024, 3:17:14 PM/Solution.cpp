// https://leetcode.com/problems/sum-of-prefix-scores-of-strings

class Solution {
public:
    const static int MOD = 1e9+7;
    const static int P = 31;
    long long compute_hash(string s) {
        long long hash = 0;
        long long pow = 1;
        for (int i=0; i<(int)s.size(); i++) {
            hash += ((s[i] - 'a' + 1)*pow) % MOD; 
            pow = (pow * P) % MOD;
        }
        return hash;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<long long, int> m;
        int N = (int)words.size();
        for (int i=0; i<N; i++) {
            long long hash = 0;
            long long pow = 1;
            for (int j=0; j<(int)words[i].size(); j++) {
                // m[compute_hash(words[i].substr(0, j))]++;
                hash += ((words[i][j] - 'a' + 1)*pow) % MOD; 
                pow = (pow * P) % MOD;
                m[hash]++;
            }
        }
        vector<int> ans;
        for (int i=0; i<N; i++) {
            int sum = 0;
            // for (int j=1; j<=(int)words[i].size(); j++) {
            //     // sum += m[compute_hash(words[i].substr(0, j))];
            // }
            long long hash = 0;
            long long pow = 1;
            for (int j=0; j<(int)words[i].size(); j++) {
                // m[compute_hash(words[i].substr(0, j))]++;
                hash += ((words[i][j] - 'a' + 1)*pow) % MOD; 
                pow = (pow * P) % MOD;
                sum += m[hash];
            }
            ans.push_back(sum);
        }


        return ans;
    }
};