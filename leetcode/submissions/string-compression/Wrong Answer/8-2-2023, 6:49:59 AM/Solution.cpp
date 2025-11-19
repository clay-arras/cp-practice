// https://leetcode.com/problems/string-compression

#include <typeinfo>
class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('.');
        int N = (int)chars.size();

        int cnt = 1;
        vector<char> ans;
        for (int i=1; i<N; i++) {
            if (chars[i-1] == chars[i]) {
                cnt++;
            } else {
                ans.push_back(chars[i-1]);
                cout << chars[i-1] << endl;
                for (auto j : to_string(cnt)) {
                    ans.push_back(j);
                    cout << typeid(j).name() << endl;
                    // cout << j << endl;
                }
                cnt = 1;
            }
        }
        return (int)ans.size();
    }
};