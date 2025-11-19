// https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum

class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int N = (int)capacity.size();

        long long pref = 0;
        long long ans = 0;
        unordered_map<string, vector<int>> m;
        for (int i=0; i<N; i++) {
            auto& l = m[to_string(capacity[i]) + "#" + to_string(pref - 2*capacity[i])];
            int cnt = 0;
            for (int j=(int)l.size()-1; j>=0; j--) {
                if ((i+1) - l[j] >= 3)
                    break;
                cnt++;
            }
            ans += (int)l.size() - cnt;
            
            m[to_string(capacity[i]) + "#" + to_string(pref)].push_back(i);
            pref += capacity[i];
        }

        return ans;
    }
};