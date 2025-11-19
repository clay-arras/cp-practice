// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int N = (int)properties.size();

        vector<pair<int, int>> arr; 
        for (auto i : properties)
            arr.push_back({i[0], i[1]});
        sort(arr.begin(), arr.end());

        int ans = 0;    
        int mx = -1;
        for (int i=N-1; i>=0; i--) {
            if (arr[i].second > mx) ans++;
            mx = max(mx, arr[i].second);
        }

        return N - ans;
    }
};
// [3, 6], [5, 5], [6, 3]