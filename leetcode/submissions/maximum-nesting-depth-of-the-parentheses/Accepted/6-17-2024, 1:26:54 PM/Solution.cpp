// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int N = (int)s.size();

        int ans = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == '(') {
                st.push('(');
            } else if (s[i] == ')') {
                st.pop();
            }
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};