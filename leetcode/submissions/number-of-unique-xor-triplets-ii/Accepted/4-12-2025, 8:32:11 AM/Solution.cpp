// https://leetcode.com/problems/number-of-unique-xor-triplets-ii

class Solution {
public:
    template<int SZ, int MXBIT> struct Trie {
        int next[SZ][2], sz[SZ], num = 0;
        int mxV = 1e9+7;
        Trie() { memset(next, 0, sizeof(next)); memset(sz, 0, sizeof(sz)); }
        void insert (int x, int a = 1) {
            int curr = 0; sz[curr] += a;
            for (int i=MXBIT-1; i>=0; i--) {
                int t = (x>>i)&1;
                if (!next[curr][t])
                    next[curr][t] = ++num;
                sz[curr = next[curr][t]] += a;
            }
        }
        int test(int x) {
            if (!sz[0]) return -mxV;
            int curr = 0;
            for (int i=MXBIT-1; i>=0; i--) {
                int t = ((x>>i)&1)^1;
                if (!next[curr][t] || !sz[next[curr][t]])
                    t ^= 1;
                curr = next[curr][t];
                if (t) x ^= (1LL<<i);
            }
            return x;
        }
    };

    int uniqueXorTriplets(vector<int>& nums) {
        int N = (int)nums.size();          
        // Trie<1500, 32> xorOne, xorTwo;
        unordered_set<int> xorOne, xorTwo;

        for (int i=0; i<N; i++) {
            for (int j=i; j<N; j++) {
                xorOne.insert(nums[i] ^ nums[j]);
            }
        }
        for (int i=0; i<N; i++) {
            for (int j : xorOne)
                xorTwo.insert(nums[i] ^ j);
        }
        return (int)xorTwo.size();
    }
};