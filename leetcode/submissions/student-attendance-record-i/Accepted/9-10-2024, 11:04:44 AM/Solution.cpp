// https://leetcode.com/problems/student-attendance-record-i

class Solution {
public:
    bool checkRecord(string s) {
        int ok1 = 0;
        int ok2 = 0;
        
        int N = (int)s.size();
        int cnt = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == 'A')
                ok1++;
            if (s[i] == 'L') {
                if (i-1 >= 0 && s[i-1] == 'L') 
                    cnt++;
                else {
                    ok2 = max(ok2, cnt);
                    cnt = 1;
                }
            }
        }
        ok2 = max(ok2, cnt);
        return (ok1 < 2 && ok2 < 3);
    }
};