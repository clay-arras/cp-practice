// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        int N = (int)s.size();
        
        int a=0, b=0;
        for (char c : s) {
            if (c == '[') a++;
            if (c == ']') b++;
        }
        if (a == 0 && b == 0) return s;
        
        string ans = "";
        for (int i=0; i<N; i++) {
            if (s[i] == '[') {
                st.push(i);
            }
            else if (s[i] == ']') {
                int t = st.top();
                st.pop();
                int j;
                for (j=t-1; j-1>=0 && s[j-1] >= '0' && s[j-1] <= '9'; j--);
                int k = stoi(s.substr(j, t-j));
                cout << k << endl;
                
                string sub = decodeString(s.substr(t+1, i-t-1));
                for (int j=0; j<k; j++) {
                    ans += sub;
                }
            }
        }
        return ans;
    }
};