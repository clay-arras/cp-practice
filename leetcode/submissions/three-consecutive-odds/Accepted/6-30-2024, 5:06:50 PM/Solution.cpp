// https://leetcode.com/problems/three-consecutive-odds

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i=1; i<(int)arr.size()-1; i++) {
            if (arr[i-1] % 2 && arr[i] % 2 && arr[i+1] % 2)
                return true;
        }
        return false;
    }
};