// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int N = (int)seats.size();
        int ans = 0;
        for (int i=0; i<N; i++) 
            ans += abs(students[i] - seats[i]);
            
        return ans;
    }
};