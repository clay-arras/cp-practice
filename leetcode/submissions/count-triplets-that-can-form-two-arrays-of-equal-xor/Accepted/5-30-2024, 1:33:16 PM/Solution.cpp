// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int N = (int)arr.size();
        vector<int> pref(N+1, 0);

        for (int i=1; i<=N; i++) {
            pref[i] += pref[i-1];
            pref[i] ^= arr[i-1];
        }

        int count = 0;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (pref[j+1] == pref[i]) 
                    count += j - i;
            }
        }
        return count;
    }
};