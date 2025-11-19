// https://leetcode.com/problems/rank-teams-by-votes

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int voters = votes.size();
        int teamsCount = votes[0].size();

        unordered_map<char, int> toInt;
        unordered_map<int, char> fromInt;
        for (int j=0; j<teamsCount; j++) {
            toInt[votes[0][j]] = j;
            fromInt[j] = votes[0][j];
        }

        vector<pair<vector<int>, int>> cnt;
        for (int i=0; i<teamsCount; i++)
            cnt.push_back({vector<int>(teamsCount, 0), i});

        for (int i=0; i<voters; i++) {
            for (int j=0; j<teamsCount; j++) {
                char c = votes[i][j];
                cnt[toInt[c]].first[j]++;
            }
        }

        sort(cnt.begin(), cnt.end(), [&](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
            for (int i=0; i<teamsCount; i++) {
                if (a.first[i] == b.first[i])
                    continue;
                return a.first[i] > b.first[i];
            }
            return fromInt[a.second] < fromInt[b.second];
        });

        string ans = "";
        for (auto i : cnt) 
            ans += fromInt[i.second];
        return ans;
    }
};