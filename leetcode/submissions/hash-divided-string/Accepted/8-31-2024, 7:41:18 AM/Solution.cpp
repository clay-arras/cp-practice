// https://leetcode.com/problems/hash-divided-string

class Solution {
public:
    string stringHash(string s, int k) {
        
        int N = (int)s.size();
        string ans = "";
        for (int i=0; i<N; i+=k) {
            int sum = 0;
            for (int j=i; j<i+k; j++) 
                sum += s[j]-'a';
            sum %= 26;
            ans += sum+'a';
        }
        return ans;
    }
};