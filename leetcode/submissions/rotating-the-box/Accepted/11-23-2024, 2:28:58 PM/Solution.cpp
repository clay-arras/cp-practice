// https://leetcode.com/problems/rotating-the-box

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int N = (int)box.size(), M = (int)box[0].size();

        vector<vector<char>> trans(M, vector<char> (N, '.'));
        for (int i=0; i<N; i++) 
            for (int j=0; j<M; j++)
                trans[j][i] = box[i][j];
        
        for (int i=0; i<M; i++)
            reverse(trans[i].begin(), trans[i].end());
            
        cout << N << " " << M << endl;
        for (int i=0; i<N; i++) {
            // int lastOpen = -1;
            set<int> l;
            for (int j=M-1; j>=0; j--) {
                if (trans[j][i] == '*') {
                    l.clear();
                    // lastOpen = -1;
                } else if (trans[j][i] == '#') {
                    if (l.empty()) {
                        continue;
                    }
                    cout << i << " " <<  j << " " << *l.rbegin() << endl;
                    cout << "swap" << endl;
                    swap(trans[j][i], trans[*l.rbegin()][i]);
                    l.erase(*l.rbegin());
                    l.insert(j);
                } else if (trans[j][i] == '.') {
                    // lastOpen = max(lastOpen, trans[j][i]);
                    l.insert(j);
                }
            }
        }

        return trans;
    }
};