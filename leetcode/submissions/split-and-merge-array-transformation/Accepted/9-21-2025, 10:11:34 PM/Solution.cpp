// https://leetcode.com/problems/split-and-merge-array-transformation

class Solution {
public:
    string n1, n2;
    int N;

    vector<string> split(string s, int l, int r) {
        string pref = s.substr(0, l);
        string sl   = s.substr(l, r - l);
        string suff = s.substr(r);
        return {pref, sl, suff};
    }
    vector<string> split(string s, int i) {
        return {s.substr(0, i), s.substr(i)};
    }

    // NOTE: dp from the original is NOT used anymore for correctness.
    // The bug was context-dependent memoization. We switch to bestDepth.
    unordered_map<string, int> bestDepth; // state -> smallest depth seen so far
    int bestAns;                          // global best (# moves)

    void dfsDepth(const string& arr, int depth) {
        if (depth >= bestAns) return; // branch-and-bound (we already have a better answer)
        auto it = bestDepth.find(arr);
        if (it != bestDepth.end() && it->second <= depth) return; // no improvement
        bestDepth[arr] = depth;

        if (arr == n2) { bestAns = depth; return; }

        for (int l = 0; l < N; ++l) {
            for (int r = l + 1; r <= N; ++r) {            // disallow empty removal
                auto s = split(arr, l, r);                 // s[0]=pref, s[1]=mid, s[2]=suff
                string c = s[0] + s[2];                    // remaining after removal
                for (int i = 0; i <= (int)c.size(); ++i) {
                    if (i == (int)s[0].size()) continue;   // skip no-op reinsertion
                    auto ins = split(c, i);
                    string nxt = ins[0] + s[1] + ins[1];
                    dfsDepth(nxt, depth + 1);
                }
            }
        }
    }

    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        N = (int)nums1.size();

        // per request: store input midway
        auto donquarist = nums1;

        // same encoding as your code (safe for N <= 6: single-digit labels)
        unordered_map<int, int> m;
        n1.clear(); n2.clear();
        for (int i = 0; i < N; i++) {
            if (!m.count(nums1[i])) m[nums1[i]] = i + 1;
            n1 += to_string(m[nums1[i]]);
        }
        for (int i = 0; i < N; i++)
            n2 += to_string(m[nums2[i]]);

        if (n1 == n2) return 0;

        bestDepth.clear();
        bestAns = 6;              // upper bound for n <= 6
        dfsDepth(n1, 0);
        return bestAns;
    }
};
