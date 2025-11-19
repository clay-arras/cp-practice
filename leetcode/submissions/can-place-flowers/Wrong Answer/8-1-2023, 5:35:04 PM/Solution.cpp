// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int N = (int)flowerbed.size();
        for (int i=1; i<N-1; i++) {
            if (!flowerbed[i-1] and !flowerbed[i] and !flowerbed[i+1]) {
                count++;
            }
        }
        if (N > 2 and !flowerbed[0] and !flowerbed[1])
            count++;
        else if (N > 2 and !flowerbed[N-2] and !flowerbed[N-1])
            count++;
        else if (N == 2 and !flowerbed[0] and !flowerbed[1])
            count = 1;

        return (count >= n);
    }
};