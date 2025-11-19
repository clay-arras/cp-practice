// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(), columnTitle.end());
        int N = (int)columnTitle.size();
        
        int roll = 1;
        int sum = 0;
        for (int i=0; i<N; i++) {
            sum += (columnTitle[i] - 'A' + 1) * roll;
            roll *= 26;
        }
        return sum;
    }
};