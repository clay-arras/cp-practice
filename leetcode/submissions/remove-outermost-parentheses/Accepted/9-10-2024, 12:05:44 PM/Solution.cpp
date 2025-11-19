// https://leetcode.com/problems/remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        int N = (int)s.size();
        
        string ans = "";
        for (int i=0; i<N; i++) {
            if (s[i] == '(') {
                st.push(i);  
            } else if (s[i] == ')') {
                int x = st.top();
                st.pop();
                if (st.empty()) {
                    ans += s.substr(x+1, i-x-1);
                }
            }
        }
        return ans;
    }
};