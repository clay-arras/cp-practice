// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int N = (int)people.size();
        int count = 1, lim = 0;
        for (int i=0; i<N; i++) {
            if (lim + people[i] > limit) {
                count++;
                lim = 0;
            } 
            lim += people[i];
        }
        return count;
    }
};