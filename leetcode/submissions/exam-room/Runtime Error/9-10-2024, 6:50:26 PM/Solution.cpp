// https://leetcode.com/problems/exam-room

class ExamRoom {
public:
    set<pair<int, pair<int, int>>> s;
    map<int, pair<set<pair<int, pair<int, int>>>::iterator, set<pair<int, pair<int, int>>>::iterator>> m;
    int N;
    bool st = false, en = false;
    
    // check if distance to zero is bigger -- if empty then set to zero
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        if (s.empty()) {
            if (st) {
                en = true;
                auto t = s.insert({(N-1)/2, {0, N-1}}).first;
                m[0] = {t, s.end()};
                m[N-1] = {s.end(), t};
                return N-1;
            } 
            st = true;   
            return 0;
        }
        
        // auto it = s.rbegin();
        auto it = prev(s.begin());
        if ((int)s.size() == 1)
            it = s.begin();
        pair<int, int> x = it->second;
        if (x.first == -INT_MAX) {
            auto l = s.insert({it->first/2, {0, x.second}}).first;
            m[0] = {l, s.end()};
            s.erase(it);
            st = true;
            return 0;
        }
        if (x.second == INT_MAX) {
            auto r = s.insert({(N-1 - x.second)/2, {x.second, N-1}}).first;
            m[N-1] = {s.end(), r};
            s.erase(it);
            en = true;
            return N-1;
        }
        
        int mid = (x.first + x.second) / 2;
        
        auto l = s.insert({(x.first + mid)/2, {x.first, mid}}).first;
        auto r = s.insert({(mid + x.second)/2, {mid, x.second}}).first;
        m[mid] = {l, r};
        cout << "PROBLEM " << endl;
        cout << it->first << " " << it->second.first << " " << it->second.second << endl;
        for (auto i : s)
            cout << i.first << " " << i.second.first << " " << i.second.second << endl;
        cout << endl;
        s.erase(it);
        return mid;
    }
    
    void leave(int p) {
        if (p == 0) {
            st = false; 
            int dist = m[p].first->second.second - m[p].first->second.first;
            s.erase(m[p].first);
            m[p].first = s.insert({dist, {-INT_MAX, m[p].first->second.second}}).first;
            return;
        }
        if (p == N-1) {
            en = false;
            int dist = m[p].second->second.second - m[p].second->second.first;
            s.erase(m[p].second);
            m[p].second = s.insert({dist, {m[p].first->second.first, INT_MAX}}).first;
            return;
        }
        
        auto l = m[p].first;
        auto r = m[p].second;
        
        s.insert({(l->second.first + r->second.second)/2, {l->second.first, r->second.second}});
        s.erase(l);
        s.erase(r);
        m[p] = {s.end(), s.end()};
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */