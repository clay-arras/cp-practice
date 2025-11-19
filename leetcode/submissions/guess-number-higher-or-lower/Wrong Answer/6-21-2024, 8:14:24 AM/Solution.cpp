// https://leetcode.com/problems/guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long lo = 1, hi = INT_MAX;
        while (hi > lo) {
            long long mid = lo + (hi - lo) / 2;
            int val = guess(mid);
            if (val > 0) {
                lo = mid + 1; 
            } else if (val < 0) {
                hi = mid;
            } else {
                return mid;
            }
        }
        return -1;
    }
};