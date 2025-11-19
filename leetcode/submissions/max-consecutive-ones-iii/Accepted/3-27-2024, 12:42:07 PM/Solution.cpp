// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        nums.insert(nums.begin(), 0);
        nums.push_back(0);
        int N = (int)nums.size();

        int l=0, r=1;
        for (r=1; r<N-1 && k > 0; r++) {
            if (nums[r] == 0) k--; 
        }
        while (r<N-1 && nums[r]==1) r++;
        cout << r << endl;

        for (int i=0; i<N; i++) {
            cout << nums[i];
            if (i == r)
                cout << ".";
        }
        cout << endl;

        int ans = r - l;
        for (; l<N-1 && r<N-1;) {
            r++;
            while (r<N-1 && nums[r]==1) r++;
            l++;
            while (l<N-1 && nums[l]==1) l++;
            ans = max(ans, r - l);
        }

        return ans - 1;
    }
};