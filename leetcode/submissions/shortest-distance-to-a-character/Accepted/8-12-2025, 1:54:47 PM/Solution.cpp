// https://leetcode.com/problems/shortest-distance-to-a-character

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        const int MXV = 2e9;
        // idea one: expanding centers. max time complexity: 2*N, stop at other char c
        
        int N = (int)s.size(); 
        vector<int> dist(N, MXV);
        
        int cnt = MXV;
        for (int i=0; i<N; i++) {
            if (s[i] == c) {
                dist[i] = 0;
                cnt = 0;
                for (int l=1; i-l >= 0 && s[i-l] != c; l++) 
                    dist[i-l] = min(dist[i-l], l);
                continue;
            } 
            cnt++;
            dist[i] = cnt;
        }
        return dist;
    }
};