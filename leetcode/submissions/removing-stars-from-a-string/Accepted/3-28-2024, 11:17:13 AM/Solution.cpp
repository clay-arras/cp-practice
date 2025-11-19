// https://leetcode.com/problems/removing-stars-from-a-string

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int N = (int)s.size();
        for (int i=0; i<N; i++) {
            if (s[i] == '*') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};