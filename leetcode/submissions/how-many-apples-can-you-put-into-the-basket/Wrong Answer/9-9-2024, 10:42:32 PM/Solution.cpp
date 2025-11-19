// https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket

class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int ans = 0;
        
        const int MX = 5e3;
        int i;
        for (i=0; i<(int)weight.size(); i++) {
            if (ans + weight[i] >= MX) 
                 break;
            ans += weight[i];
        }
        
        return i+1;
    }
};
