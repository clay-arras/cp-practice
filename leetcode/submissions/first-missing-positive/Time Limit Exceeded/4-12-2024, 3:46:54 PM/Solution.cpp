// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = (int)nums.size();
        nums.push_back(-1);
        for (int i = 0; i <= N; i++) {
            int pt = i;
            while (nums[pt] >= 0 && 
                   nums[pt] <= N && 
                   pt != nums[pt]) {
                    
                int tmp = nums[pt];
                nums[pt] = nums[tmp];
                nums[tmp] = tmp;
            }
           
            for (auto i : nums)
                cout << i << " ";
            cout << endl;
        }

        int ans = N + 1;
        for (int i = 1; i <= N; i++) {
            if (nums[i] != i) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};