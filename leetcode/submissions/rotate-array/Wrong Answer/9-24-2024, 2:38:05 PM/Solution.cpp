// https://leetcode.com/problems/rotate-array

class Solution {
public:

    const static long long MX = 2e5+1;
    void rotate(vector<int>& nums, int k) {
        int N = (int)nums.size();
        
        const auto sol1 = [&]() {
            vector<int> ans;
            for (int i=(MX*N-k)%N; i<N; i++)
                ans.push_back(nums[i]);
            for (int i=0; i<(MX*N-k)%N; i++)
                ans.push_back(nums[i]);
            nums = ans;
        };        
        const auto sol2 = [&]() {
            k = k%N;
            if (!k) return;
            if (N%k) {
                int ptr = nums[0];
                for (int i=1; i<=N; i++) {
                    int tmp = nums[(i*k)%N];
                    nums[(i*k)%N] = ptr;
                    ptr = tmp;
                }
            } else {
                for (int j=0; j<k; j++) {
                    int ptr = nums[j];
                    for (int i=1; i<=N/k; i++) {
                        cout << j << " " << k*i + j << endl;
                        int tmp = nums[(k*i + j)%N];
                        nums[(k*i + j)%N] = ptr;
                        ptr = tmp;
                    }
                }
            }
        };

        

        sol2();
    }
};