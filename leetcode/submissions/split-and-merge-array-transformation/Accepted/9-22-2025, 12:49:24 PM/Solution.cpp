// https://leetcode.com/problems/split-and-merge-array-transformation

class Solution {
public:
    string n1, n2;
    int N;

    vector<string> split(string s, int l, int r) {
        string pref = s.substr(0, l);
        string sl = s.substr(l, r-l);
        string suff = s.substr(r, N);
        return {pref, sl, suff};
    }
    vector<string> split(string s, int i) {
        return {s.substr(0, i), s.substr(i, N)};
    }

    unordered_map<string, int> dp;
    int dfs(string arr) {
        if (dp.count(arr) && dp[arr] != -1)
            return dp[arr];
        if (dp.count(arr) && dp[arr] == -1)
            return 6;
        if (arr == n2)
            return dp[arr] = 0;

        dp[arr] = -1; // processing

        int ans = 6;
        for (int l=0; l<=N; l++) {
            for (int r=l+1; r<=N; r++) {
                auto s = split(arr, l, r);

                string c = s[0] + s[2];
                for (int i=0; i<(int)c.size(); i++) {
                    auto ins = split(c, i);
                    ans = min(ans, dfs(ins[0] + s[1] + ins[1]) + 1);
                }
            }
        }
        return dp[arr] = ans;
    }
    
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        N = (int)nums1.size();

        unordered_map<int, int> m;
        n1 = "", n2 = "";
        for (int i=0; i<N; i++) {
            if (m.count(nums1[i]))
                n1 += to_string(m[nums1[i]]);
            else {
                m[nums1[i]] = i+1;
                n1 += to_string(m[nums1[i]]);
            }
        }
        for (int i=0; i<N; i++) 
            n2 += to_string(m[nums2[i]]);
        
        int ans = dfs(n1); 
        return ans;
    }
};