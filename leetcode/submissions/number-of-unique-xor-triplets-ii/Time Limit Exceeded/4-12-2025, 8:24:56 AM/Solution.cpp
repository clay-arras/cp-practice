// https://leetcode.com/problems/number-of-unique-xor-triplets-ii

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int N = (int)nums.size();          
        set<int> xorOne, xorTwo;

        for (int i=0; i<N; i++) {
            for (int j=i; j<N; j++) {
                xorOne.insert(nums[i] ^ nums[j]);
            }
        }
        for (int i=0; i<N; i++) {
            for (int j : xorOne)
                xorTwo.insert(nums[i] ^ j);
        }
        return (int)xorTwo.size();
    }
};