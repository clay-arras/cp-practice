// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    int maxVowels(string s, int k) {
        set<int>vowels({'a', 'e', 'i', 'o', 'u'});
        int N = (int)s.size();

        int ans = 0;
        for (int i=0; i<k; i++) {
            ans += (vowels.count(s[i]));
        }
        int count = ans;
        for (int i=k; i<N; i++) {
            count -= (vowels.count(s[i-k]));
            count += (vowels.count(s[i]));
            ans = max(ans, count);
        }
        return ans;
    }
};