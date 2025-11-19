// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(), columnTitle.end());
        int N = (int)columnTitle.size();
        
        long long roll = 1;
        long long sum = 0;
        for (int i=0; i<N; i++) {
            sum += (columnTitle[i] - 'A' + 1LL) * roll;
            roll *= 26;
        }
        return sum;
    }
};