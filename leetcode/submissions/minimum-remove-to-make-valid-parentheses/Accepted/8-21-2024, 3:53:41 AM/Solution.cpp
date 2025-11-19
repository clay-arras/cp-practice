// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int N = (int)s.size();
        stack<int> st;

        vector<bool> keep(N, false);
        for (int i=0; i<N; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    int j = st.top();
                    st.pop();
                    keep[i] = true, keep[j] = true;
                }
            } else {
                keep[i] = true;
            }
        }
        string ans = "";
        for (int i=0; i<N; i++) {
            if (keep[i])
                ans += s[i];
        }

        return ans;
    }
};