// https://leetcode.com/problems/relative-sort-array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> end;
        map<int, int> m;

        for (auto i : arr2)
            m[i]++;
        for (auto i : arr1) {
            if (m[i]) m[i]++;
            else end.push_back(i);
        }

        vector<int> ans;
        for (auto i : arr2) {
            for (int j=0; j<m[i]-1; j++) 
                ans.push_back(i);
        }

        sort(end.begin(), end.end());
        for (auto i : end) 
            ans.push_back(i);
        
        return ans;
    }
};