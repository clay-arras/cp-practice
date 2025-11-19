// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        int N = (int)s.size();
        string ans = "";
        for (int i=0; i<N; i++) {
            if (s[i] == '[') {
                st.push(i);
            }
            else if (s[i] == ']') {
                int t = st.top();
                st.pop();
                int k = s[t-1]-'0';
                cout << k << endl;
                cout << s.substr(t+1, i-t-1) << endl;
                string sub = decodeString(s.substr(t+1, i-t-1));
                for (int j=0; j<k; j++) {
                    ans += sub;
                }
            }
            else if (s[i] <= 'z' && s[i] >= 'a') 
                ans += s[i];
        }
        return ans;
    }
};