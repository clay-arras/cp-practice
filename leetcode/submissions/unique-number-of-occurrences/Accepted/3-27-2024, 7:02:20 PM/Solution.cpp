// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> freq;
        for (int i : arr)
            freq[i]++;
        map<int, int> m;
        for (auto [key, val] : freq) {
            m[val]++;
            if (m[val] > 1) {
                return false;
            }
        }
        return true;
    }
};