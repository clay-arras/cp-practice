// https://leetcode.com/problems/count-pairs-with-xor-in-a-range

class Solution {
public:
    const static int BITS = 16;
    static long long binstrToInt(string s) {
        return bitset<BITS>(s).to_ulong();
    }
    static string intToBinstr(long long i) {
        return bitset<BITS>(i).to_string();
    }

    struct Trie {
        vector<Trie*> pt;
        int sz = 0;
        Trie() { pt = vector<Trie*>(2, nullptr); }
        auto insert(string s) {
            sz++;
            if (s.empty()) return false;
            if (pt[0] == nullptr)  pt[0] = new Trie();
            if (pt[1] == nullptr)  pt[1] = new Trie();
            return pt[s[0] - '0']->insert(s.substr(1));
        }
        long long search(string s, int pref, int k) {
            int val = (1 << (int)s.size());
            int mx = pref*val + (val-1);
            int mn = pref*val;

            if (mn > k) return 0;
            if (mx <= k) return sz;

            int ans = 0;
            if (pt[1] != nullptr) ans += pt[1]->search(s.substr(1), 2*pref + ((s[0]-'0') ^ 1), k);
            if (pt[0] != nullptr) ans += pt[0]->search(s.substr(1), 2*pref + ((s[0]-'0') ^ 0), k);
            return ans;
        }
    };

    int countPairs(vector<int>& nums, int low, int high) {
        int N = (int)nums.size();
        auto lessThanK = [&](int k) { 
            Trie* obj = new Trie();
            int ans = 0;
            for (int i=0; i<N; i++) {
                ans += obj->search(intToBinstr(nums[i]), 0, k);
                obj->insert(intToBinstr(nums[i]));
            }
            return ans;
        };
        return lessThanK(high) - lessThanK(low - 1);
    }
};