// https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int N = (int)s.size();
        unordered_map<char, int> m;
        for (char c : s) 
            m[c]++;

        string ans = "";
        bool ok = false;
        for (int i=0; i<N; i++) {
            if (ok) {
                for (char c='a'; c<='z'; c++) {
                    if (m[c] > 0) {
                        m[c]--;
                        ans.push_back(c);
                        break;
                    }
                }
            } else {
                for (char c=target[i]; c<='z'; c++) {
                    if (m[c] > 0) {
                        m[c]--;
                        ans.push_back(c);
                        if (c > target[i])
                            ok = true;
                        break;
                    }
                }
                if ((int)ans.size() != i+1) {
                    ok = true; 
                    for (char c='a'; c<='z'; c++) {
                        if (m[c] > 0) {
                            m[c]--;
                            ans.push_back(c);
                            break;
                        }
                    }
                }
            }
        }
        // edge case: if ans == target, but there's a way to swap s.t. its greater
        // neg: ba -> ""
        // pos: ab -> ba
        
        string t = s;
        sort(t.rbegin(), t.rend());
        if (t == target) return "";

        cout << ans << endl;
        if (ans <= target) {
            // can swap
            unordered_map<char, int> mm;
            for (int i=N-1; i>=0; i--) {
                for (char c=target[i]+1; c<='z'; c++) {
                    if (mm.count(c)) {
                        swap(ans[mm[c]], ans[i]);
                        sort(ans.begin() + i + 1, ans.end());
                        return ans;
                    }
                }

                mm[ans[i]] = i; // want the smallest index
            }
        }
        // dcbadcbadcbadcbadcbadcbadcbadcbadcbadcbadcbadcbaab

        return ans > target ? ans : "";
    }
};