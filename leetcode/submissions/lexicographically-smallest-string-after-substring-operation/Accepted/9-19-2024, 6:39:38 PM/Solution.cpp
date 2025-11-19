// https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation

class Solution {
public:
    string smallestString(string s) {
        // two cases:
        // if char is 'a' then skip
        // start window after first non-'a' or last one
        // keep going while there is no 'a'
        int N = (int)s.size();
        int i=0;
        while (i<N-1 && s[i] == 'a')
            i++;
        int j = 1;
        while (i+j<N && s[i+j] != 'a')
            j++;
        cout << i << " " << j << endl;
        string ans = "";
        for (int k=0; k<N; k++) {
            if (k >= i && k < i+j)
                ans += (s[k]-'a'-1+26)%26 + 'a';
            else 
                ans += s[k];
        }

        return ans;
    }
};