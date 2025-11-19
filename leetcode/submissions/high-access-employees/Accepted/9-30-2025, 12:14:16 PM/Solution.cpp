// https://leetcode.com/problems/high-access-employees

class Solution {
public:
    struct Time {
        Time(string s) {
            h = stoi(s.substr(0, 2));
            m = stoi(s.substr(2, 2));
        }
        int h, m; 

        bool isSameHour(Time& b) {
            int ax = this->h * 60 + this->m;
            int bx = b.h *60 + b.m;
            return abs(ax - bx) < 60;
        }
    };

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<Time>> mp;
        for (auto t : access_times) 
            mp[t[0]].push_back(Time(t[1]));

        vector<string> ans;
        for (auto& [k, v] : mp) {
            sort(v.begin(), v.end(), [&](const Time& a, const Time& b) {
                if (a.h == b.h)
                    return a.m < b.m;
                return a.h < b.h;
            });

            int sz = (int)v.size();
            for (int i=1; i<sz-1; i++) {
                if (v[i-1].isSameHour(v[i+1])) {
                    ans.push_back(k);
                    break;
                }
            }
        }
        return ans;
    }
};