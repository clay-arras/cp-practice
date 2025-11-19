// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int N = (int)people.size();
        int cnt = 0;
        for (int r=N-1, l=0; r>=l; r--, cnt++) 
            if (people[l] + people[r] <= limit) 
                l++;

        return cnt;
    }
};