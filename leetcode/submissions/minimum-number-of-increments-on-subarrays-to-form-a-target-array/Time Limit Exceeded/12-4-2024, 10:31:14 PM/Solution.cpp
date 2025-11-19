// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array

class Solution {
public:
    unordered_map<string, int> memo;
    string getKey(int start, int end, int k) {
        return to_string(start) + "#" + to_string(end) + "#" + to_string(k);
    }

    int solve(vector<int>& target, int start, int end, int k) {
        if (start > end) 
            return 0;
        
        string key = getKey(start, end, k);
        if (memo.count(key))
            return memo[key];
        
        int minIdx = end, center = (start+end)/2;
        for (int i = 0; i <= center-start; i++) {
            if (target[center+i] < target[minIdx]) 
                minIdx = center+i;
            if (target[center-i] < target[minIdx]) 
                minIdx = center-i;
        }

        int minOps = max(0, target[minIdx] - k);
        int l = solve(target, start, minIdx-1, target[minIdx]);
        int r = solve(target, minIdx+1, end, target[minIdx]);

        return memo[key] = minOps + l + r;
    }

    int minNumberOperations(vector<int>& target) {
        return solve(target, 0, target.size()-1, 0);
    }
};