// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=1, m=1;
        int l1=(int)nums1.size(), l2=(int)nums2.size();

        while(n <= l1 and m <= l2) {
            if (n + m == (l1 + l2 + 1) / 2) {
                if ((l1+l2) % 2 == 0) {
                    return -543;
                    return min(nums1[n-1], nums2[m-1]);
                } else {
                    return -32123;
                    return (nums1[n-1] + nums2[m-1]) / 2;
                }
            }
            if (nums1[n-1] < nums2[m-1]) n++;
            else m++;
        }
        return -1;
    }
};