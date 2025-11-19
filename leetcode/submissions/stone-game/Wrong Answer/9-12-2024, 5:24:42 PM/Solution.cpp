// https://leetcode.com/problems/stone-game

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = (int)piles.size();
        int a = 0, b = 0;
        for (int l=0, r=N-1, t=1; l<r; t^=1) {
            int tl=l, tr=r;
            while (tl+1<tr-1 && piles[tl] == piles[tr]) tl++, tr--; 
            if (piles[l] > piles[r] || (piles[l] == piles[r] && piles[tl] < piles[tr])) {
                (t ? a : b) += piles[l];
                l++;
            } else {
                (t ? a : b) += piles[r];
                r--;
            }
            cout << l << " " << r << endl;
        }
        return a > b;
    }
};