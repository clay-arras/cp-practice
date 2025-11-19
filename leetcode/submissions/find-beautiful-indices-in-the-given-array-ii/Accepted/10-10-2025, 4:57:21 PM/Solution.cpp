// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii

class Solution {
public:
    vector<int> rabin_karp(string const& s, string const& t) {
        const int p = 31; 
        const int m = 1e9 + 9;
        int S = s.size(), T = t.size();
    
        vector<long long> p_pow(max(S, T)); 
        p_pow[0] = 1; 
        for (int i = 1; i < (int)p_pow.size(); i++) 
            p_pow[i] = (p_pow[i-1] * p) % m;
    
        vector<long long> h(T + 1, 0); 
        for (int i = 0; i < T; i++)
            h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
        long long h_s = 0; 
        for (int i = 0; i < S; i++) 
            h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 
    
        vector<int> occurrences;
        for (int i = 0; i + S - 1 < T; i++) {
            long long cur_h = (h[i+S] + m - h[i]) % m;
            if (cur_h == h_s * p_pow[i] % m)
                occurrences.push_back(i);
        }
        return occurrences;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int N = (int)s.size();
        vector<int> vj = rabin_karp(b, s);

        vector<int> intv(N, 0);
        int last = 0;
        for (int i : vj) {
            last = max(last, i-k);
            for (int j=last; j<=i+k && j<N; j++)
                intv[j] = 1;
            last = max(last, i+k);
        }

        vector<int> vi = rabin_karp(a, s);
        vector<int> ans;
        for (int i : vi)
            if (intv[i])
                ans.push_back(i);

        return ans;
    }
};