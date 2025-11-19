// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        int N = (int)flowerbed.size();
        for (int i=1; i<N-1; i++) {
            if (!flowerbed[i-1] and !flowerbed[i] and !flowerbed[i+1]) {
                count++;
                flowerbed[i] = 1;
            }
        }
        
        return (count >= n);
    }
};