// https://leetcode.com/problems/strong-password-checker

class Solution {
public:
    int strongPasswordChecker(string password) {
        set<int> Up = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        set<int> Lo = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        set<int> Di = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


        int N = (int)password.length();

        int req1 = 0, req2 = 0, req3 = 0;
        for (int i=0; i<N; i++) {
            req1 |= Up.count(password[i]);
            req2 |= Lo.count(password[i]);
            req3 |= Di.count(password[i]);
        }

        vector<int> len;
        int cnt = 1;
        for (int i=1; i<N; i++) {
            if (password[i] == password[i-1]) {
                cnt++;
            } else {
                len.push_back(cnt);
                cnt = 1;
            }
        }
        len.push_back(cnt);

        int ans = 0;
        if (N > 20) {
            while (N > 20) {
                int j = 0, best = 4;
                for (int i=0, ln=(int)len.size(); i<ln; i++) {
                    if (len[i] % 3 < best and len[i] >= 3) {
                        j = i;
                        best = len[i] % 3;
                    }
                }
                len[j]--, N--, ans++;
            }

            int tot = 0;
            for (auto i : len) {
                tot += max(0, i / 3);
            }
            ans += max(tot, !req1 + !req2 + !req3) + max(N - 20, 0);
        } else if (N >= 6 and N <= 20) {
            int tot = 0;
            for (auto i : len) {
                tot += max(0, i / 3);
            }
            ans += max(tot, !req1 + !req2 + !req3);
        } else if (N < 6) {
            ans += max(abs(N - 6), !req1 + !req2 + !req3);
        }

        return ans;
    }
};
