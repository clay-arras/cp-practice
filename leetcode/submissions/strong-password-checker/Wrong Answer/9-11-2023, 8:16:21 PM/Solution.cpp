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

        for (auto i : len)
            cout << i << endl;

        int ans = 0;
        if (N > 20) {
            for (int i=0, ln=(int)len.size(); i<ln and N>20; i++) {
                int val = min(abs(N - 20), max(0, len[i] - 2));
                len[i] -= val;
                N -= val;
                ans += val;
            }
            cout << "--" << endl;
            for (auto i : len)
                cout << i << endl;
            cout << ans << endl;
            int tot = 0;
            for (auto i : len) {
                tot += max(0, i / 3);
            }
            cout << tot << endl;
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
        // 3 - 1
        // 4 - 1
        // 5 - 1
        // 6 - 2 
        // 7 - 2
        // 8 - 2
        // 9 - 3

        return ans;
    }
};

// 40 minutes

// aaaa - 1
// bbbaaa - 2
// bbbbbaaa - 3
// bbbbaaabbb

// bbabbabbabb

// 12BaaccccccbbbsslkkKKk121
// 7 - 3
// 6 - 2
// 5 - 2 bbabbabb
// 4 - 1
// 3 - 1
// tot += cnsc / 2

// adds:
// ext + 1 if not lowercase, not uppercase, not digit
// num_needed = max(tot, ext)

// min(abs(str.length() - 6), abs(str.length() - 20))
// after: decide add or remove


// if len > 20
// trim first then replace
// bbbbbaaabbbbbb - 3 1 4 = 8
// 14
// bbaabbbbbaaaab - 5
// vector of lengths: 2 2 5 4 1
// first cut it down: 2 2 2 3 1
// 
// down to 7