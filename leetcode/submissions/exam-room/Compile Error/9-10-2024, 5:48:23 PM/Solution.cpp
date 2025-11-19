// https://leetcode.com/problems/exam-room

class ExamRoom {
public:
    set<pair<int, pair<int, int>>> s;
    map<int, pair<set<pair<int, pair<int, int>>>::iterator, set<pair<int, pair<int, int>>>::iterator>> m;
    int N;
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        auto it = s.rbegin();
        pair<int, int> x = *it;
        int mid = (x.first + x.second) / 2;
        
        auto l = s.insert({(x.first + mid)/2, {x.first, mid}}).first;
        auto r = s.insert({(mid + x.second)/2, {mid, x.second}}).first;
        m[mid] = {l, r};
        s.erase(it);
    }
    
    void leave(int p) {
        auto l = m[p].first;
        auto r = m[p].second;
        
        s.insert({(l.second.first + r.second.second)/2, {l.second.first, r.second.second}});
        s.erase(l);
        s.erase(r);
        m[p] = {nullptr, nullptr};
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */