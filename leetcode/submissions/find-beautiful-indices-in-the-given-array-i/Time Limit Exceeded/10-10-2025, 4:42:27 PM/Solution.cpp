// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        // step 1: find all possible j indices by comparing substrings O(N)
        // step 2: create an array for all j, s.t. the distance k away are all labeled with corresponding j
        // step 3: loop through and find all i indices, and check if there exist j

        int N = (int)s.size();
        vector<int> vj;
        for (int i=0; i<=N-(int)b.size(); i++) {
            if (b == s.substr(i, b.size())) 
                vj.push_back(i); 
        }

        vector<int> intv(N, 0);
        for (int i : vj) {
            for (int j=-k; j<=k; j++)
                if (i + j >= 0 && i + j < N)
                    intv[i+j] = 1;
        }

        vector<int> vi;
        for (int i=0; i<=N-(int)a.size(); i++) {
            if (a == s.substr(i, a.size()) && intv[i]) 
                vi.push_back(i);
        }

        return vi;
    }
};