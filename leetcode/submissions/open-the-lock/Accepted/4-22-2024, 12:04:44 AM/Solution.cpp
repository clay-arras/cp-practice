// https://leetcode.com/problems/open-the-lock

class Solution {
public:
    const static int MAXN = 1e5 + 4;
    map<string, int> m;

    string t;
    int bfs(string s) {
        queue<string> q;

        if (m[t] == -1 || m[s] == -1)
            return -1;

        m[s] = 0;
        q.push(s);

        while (!q.empty()) {
            string x = q.front();
            q.pop();
            if (m[x] == -1)
                continue;
            if (x == t)
                return m[x];

            for (int i = 0; i < 4; i++) {
                for (int p = -1; p <= 1; p += 2) {
                    string n = x.substr(0, i) +
                               to_string(((x[i] - '0') + p + 10) % 10) +
                               x.substr(i + 1, string::npos);

                    if (m[n] == 0) {
                        q.push(n);
                        m[n] = m[x] + 1;
                    }
                }
            }
        }
        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        t = target;
        for (string s : deadends)
            m[s] = -1;
        
        return bfs("0000");
    }
};