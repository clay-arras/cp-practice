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

    int bfs(string start) {
        if (start == n2) return 0;
        unordered_map<string, int> dist;
        queue<string> q;
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            string arr = q.front(); q.pop();
            int d = dist[arr];

            for (int l = 0; l < N; ++l) {
                for (int r = l + 1; r <= N; ++r) {          // non-empty removal
                    auto s = split(arr, l, r);               // s[0]=pref, s[1]=mid, s[2]=suff
                    string c = s[0] + s[2];

                    for (int i = 0; i <= (int)c.size(); ++i) {
                        if (i == (int)s[0].size()) continue; // skip no-op reinsertion
                        auto ins = split(c, i);
                        string nxt = ins[0] + s[1] + ins[1];

                        if (!dist.count(nxt)) {
                            dist[nxt] = d + 1;
                            if (nxt == n2) return d + 1;     // first hit is optimal
                            q.push(nxt);
                        }
                    }
                }
            }
        }
        return -1; // unreachable per constraints
    }

    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        N = (int)nums1.size();

        auto donquarist = nums1; // stored as requested

        unordered_map<int,int> m;
        n1.clear(); n2.clear();
        for (int i = 0; i < N; ++i) {
            if (!m.count(nums1[i])) m[nums1[i]] = i + 1;
            n1 += to_string(m[nums1[i]]);
        }
        for (int i = 0; i < N; ++i) {
            n2 += to_string(m[nums2[i]]);
        }

        return bfs(n1);
    }
};
