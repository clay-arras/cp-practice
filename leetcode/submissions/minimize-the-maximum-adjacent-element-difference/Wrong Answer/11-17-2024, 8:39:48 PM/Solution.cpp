// https://leetcode.com/problems/minimize-the-maximum-adjacent-element-difference

class Solution {
public:
    template<class T>
    T firstTrue(T l, T r, function<bool(T)> f) {
        r++;
        while (l < r) {
            T mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int minDifference(vector<int>& nums) {
        vector<int> pos;
        for (auto i : nums) {
            if (i > 0)
                pos.push_back(i);
        }
        if ((int)pos.size() == 0)
            return 0;
        if ((int)pos.size() == (int)nums.size()) {
            int mx = 0;
            for (int i=1; i<(int)nums.size(); i++) {
                mx = max(mx, abs(nums[i] - nums[i-1]));
            }
            return mx;
        }

        if (nums[0] == -1) {
            int first = 0;
            for (int i=0; i<(int)nums.size(); i++) {
                if (nums[i] > 0) {
                    first = nums[i];
                    break;
                }
            }
            nums.insert(nums.begin(), first);
        }
        if (nums[(int)nums.size()-1] == -1) {
            int last = 0;
            for (int i=(int)nums.size()-1; i>=0; i--) {
                if (nums[i] > 0) {
                    last = nums[i];
                    break;
                }
            }
            nums.push_back(last);
        }
        vector<int> newNum;
        newNum.push_back(nums[0]);
        newNum.push_back(nums[1]);
        for (int i=2; i<(int)nums.size(); i++) {
            if (nums[i] == -1 && newNum[(int)newNum.size()-1] == -1 && newNum[(int)newNum.size()-2] == -1)
                continue;
            newNum.push_back(nums[i]);
        }

        function<bool(int)> ok = [&](int k) -> bool {
            int x = *min_element(pos.begin(), pos.end()) + k;
            int y = *max_element(pos.begin(), pos.end()) - k;
            vector<int> nums2 = newNum;

            int maxDiff = 0;
            for (int i=1; i<(int)nums2.size(); i++){
                if (nums2[i] == -1) {
                    if (i+1 < (int)nums2.size() && nums2[i+1] == -1) {
                        auto check = [&](int a, int b) {
                            int ans = max(abs(nums2[i-1] - a), abs(nums2[i+2] - b));
                            ans = max(ans, abs(a-b));
                            return ans;
                        };
                        maxDiff = max(maxDiff, min(check(x, y), min(check(y, x), min(check(x, x), check(y, y)))));
                        i++;
                        i++;
                    } else {
                        // int chooseX = abs(nums2[i-1] - x);
                        // int chooseY = abs(nums2[i-1] - y);
                        int chooseX = max(abs(nums2[i-1] - x), abs(nums2[i+1] - x));
                        int chooseY = max(abs(nums2[i-1] - y), abs(nums2[i+1] - y));
                        maxDiff = max(maxDiff, min(chooseX, chooseY));
                        if (chooseX == min(chooseX, chooseY)) {
                            nums2[i] = x;
                        } else {
                            nums2[i] = y;
                        }
                        i++;
                    }
                } else {
                    if (nums2[i-1] == -1)
                        continue;
                    maxDiff = max(maxDiff, abs(nums2[i] - nums2[i-1]));
                }
            }
            return maxDiff <= k;
        };

        int k = firstTrue(0, INT_MAX-1, ok); 
        return k;
    }
};