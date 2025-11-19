// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int N = (int)chars.size();

        int cnt = 1;
        int j=0;
        for (int i=0; i<N-1; i++) {
            if (chars[i] == chars[i+1]) {
                cnt++;
            } else {
                if (cnt == 1) {
                    chars[j] = chars[i];
                    j++;
                } else {
                    string s = chars[i] + to_string(cnt);
                    for (int t=0; t<(int)s.size(); t++, j++) {
                        chars[j] = s[t];
                    } 
                    cnt = 1;
                }
            }
        }
        if (cnt == 1) {
            chars[j] = chars[N-1];
            j++;
        } else {
            string s = chars[N-1] + to_string(cnt);
            for (int t=0; t<(int)s.size(); t++, j++) {
                chars[j] = s[t];
            } 
            cnt = 1;
        }

        return j;
    }
};