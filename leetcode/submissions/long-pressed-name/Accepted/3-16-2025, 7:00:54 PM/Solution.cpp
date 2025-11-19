// https://leetcode.com/problems/long-pressed-name

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int N = (int)name.size();
        int M = (int)typed.size();
        
        int i=0, j=0; 
        while (i<N && j<M) {
            if (name[i] == typed[j]) {
                if (i+1<N && name[i] != name[i+1]) {
                    while (j<M && typed[j] == name[i]) j++;
                    i++;
                } else {
                    i++, j++;
                }
            } else {
                return false;
            }
        }
        for (int k=j; k<M; k++) {
            if (typed[k] != name[N-1])
                return false;
        }
        return (i == N);
    }
}; 