// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m;
        for (int i=0; i<(int)arr1.size(); i++) {
            while (arr1[i] > 0) {
                m[arr1[i]]++;
                arr1[i] /= 10;
            }
        }
        
        int ans = 0;
        const auto fn = [](int k) {
            int i=0;
            while (k > 0) {
                k /= 10;
                i++;
            }
            return i;
        };
        for (int i=0; i<(int)arr2.size(); i++) {
            while (arr2[i] > 0) {
                if (m[arr2[i]]) {
                    ans = max(ans, fn(arr2[i]));
                }
                arr2[i] /= 10;
            }
        }
        return ans;
    }
};