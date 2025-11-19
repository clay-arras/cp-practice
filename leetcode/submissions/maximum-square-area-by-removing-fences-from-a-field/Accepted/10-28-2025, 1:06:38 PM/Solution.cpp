// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9+7;
        unordered_map<int, bool> hDist, vDist;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        for (int i=0; i<(int)hFences.size(); i++)
            for (int j=i+1; j<(int)hFences.size(); j++)
                hDist[abs(hFences[i] - hFences[j])] = true;

        for (int i=0; i<(int)vFences.size(); i++)
            for (int j=i+1; j<(int)vFences.size(); j++)
                vDist[abs(vFences[i] - vFences[j])] = true;
        

        int maxS = -1;
        for (auto [k, v] : hDist) {
            if (vDist.count(k)) 
                maxS = max(maxS, k);
        }
        if (maxS == -1)
            return -1;
        return (maxS * 1LL * maxS) % MOD;
    }
};