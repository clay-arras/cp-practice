// https://leetcode.com/problems/exam-room

class ExamRoom {
public:
    set<int> s;
    int N;
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        if ((int)s.size() <= 1) {
            if ((int)s.size() == 0 || (*s.begin() >= N - *s.begin())) {
                s.insert(0);
                return 0;
            } else {
                s.insert(N-1);
                return N-1;
            }
        }

        auto l = s.begin();
        auto r = ++s.begin();

        int maxDist = -1;
        int cand = -1;
        if (*s.begin() > maxDist) {
            cand = 0;
            maxDist = *s.begin();
        }

        for (; r != s.end(); ++l, ++r) {
            int dist = (*r - *l) / 2;
            if (dist > maxDist) {
                cand = *l + dist;
                maxDist = dist;
            }
        }

        if (N-1-*s.rbegin() > maxDist) {
            cand = N-1;
            maxDist = N-1-*s.rbegin();
        }

        s.insert(cand);
        return cand;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */