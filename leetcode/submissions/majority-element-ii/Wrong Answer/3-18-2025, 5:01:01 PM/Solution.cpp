// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int candidate1 = -804932894321;

        int N = (int)nums.size();
        if (N < 3) {
            auto i = std::unique(nums.begin(), nums.end());
            nums.resize(std::distance(nums.begin(), i));
            return nums;
        }

        for (int i=0; i<N; ++i) {
            if (count1 == 0) {
                candidate1 = nums[i];
                count1 += 2;
            } else {
                count1 += (nums[i] == candidate1 ? 2 : -1);
            }
        }

        int count2 = 0;
        int candidate2 = -9102839741;

        std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        // std::random_device rd;
        // std::mt19937 gen(rd());

        std::uniform_int_distribution<> distrib(-INT_MAX, INT_MAX);
        // srand(static_cast<unsigned int>(time(0)));

        for (int i=0; i<N; i++)
            if (nums[i] == candidate1) {
                int t = distrib(rng);
                cout << t << endl;
                nums[i] = t;
            }

        for (int i=0; i<N; ++i) {
            if (count2 == 0) {
                candidate2 = nums[i];
                count2 += 2;
            } else {
                count2 += (nums[i] == candidate2 ? 2 : -1);
            }
        }
        vector<int> ans;
        if (candidate1 != -804932894321 && count1)
            ans.push_back(candidate1);
        if (candidate2 != -9102839741 && count2)
            ans.push_back(candidate2);

        return ans;
    }
};