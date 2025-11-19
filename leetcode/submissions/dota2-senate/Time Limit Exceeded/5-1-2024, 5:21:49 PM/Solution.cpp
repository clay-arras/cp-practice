// https://leetcode.com/problems/dota2-senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        int N = (int)senate.size();
        queue<char> q;
        for (int i=0; i<N; i++)
            q.push(senate[i]);

        int rbans = 0, dbans = 0;
        while (q.size() > 1) {
            while (q.size() > 1 && rbans >= 1 && q.front() == 'R') {
                q.pop(); 
                rbans--;
            }
            while (q.size() > 1 && dbans >= 1 && q.front() == 'D') {
                q.pop(); 
                dbans--;
            }
            char f = q.front();
            q.push(f);
            q.pop();
            rbans += (int)(f == 'D');
            dbans += (int)(f == 'R');
            cout << f << endl;
            cout << rbans << " " << dbans << endl;
        }
        // while (!q.empty()) {
        //     cout << q.front() << endl;
        //     q.pop();
        // }
        return (q.front() == 'R' ? "Radiant" : "Dire");
    }
};