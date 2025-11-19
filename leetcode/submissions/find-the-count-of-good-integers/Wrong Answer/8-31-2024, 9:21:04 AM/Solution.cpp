// https://leetcode.com/problems/find-the-count-of-good-integers

class Solution {
public:
    unordered_map<string, bool> m;
    int N, K;
    void permute(string s) {
        if ((int)s.size() == ceil(N*1.0/2)) {
            if (stoi(s) % K || s[(int)s.size()-1] == '0')
                return;
            cout << s << endl;
            string en = "0000000000";
            for (int i=0; i<(int)s.size(); i++) {
                en[s[i]-'0'] += 2;
                if (!i) en[s[i]-'0']--;
            }
            m[en] = true;
            cout << en << endl;
            cout << endl;
        } else {
            for (int i=0; i<=9; i++) 
                permute(s + to_string(i));
        }
    }


    long long countGoodIntegers(int n, int k) {
        N = n, K = k;
        permute("");

        long long ans = 0;
        // for (auto [k, v] : m) {
        //     cout << k << " " << v << endl;
        //     long long tmp = tgamma(N+1);
        //     for (int i=0; i<=9; i++) {
        //         tmp /= tgamma(k[i]-'0'+1);
        //     }
        //     ans += tmp;
        // }

        return ans;
    }
};