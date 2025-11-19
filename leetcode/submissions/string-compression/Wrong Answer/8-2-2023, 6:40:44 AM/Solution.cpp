// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int N = (int)chars.size();

        int cnt = 1;
        vector<char> ans;
        for (int i=1; i<N; i++) {
            if (chars[i-1] == chars[i]) {
                cnt++;
            } else {
                cnt = 1;
                ans.push_back(chars[i-1]);
                ans.push_back(cnt);
            }
        }

        for (auto i : ans) {
            cout << i << endl;
        }
        return 0;
    }
};