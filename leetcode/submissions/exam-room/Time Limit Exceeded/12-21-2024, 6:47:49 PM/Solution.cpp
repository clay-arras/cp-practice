// https://leetcode.com/problems/exam-room

class ExamRoom {
public:
    // Store {distance, {start, end}}
    set<pair<int, pair<int, int>>> intervals;
    int N;
    set<int> seated;  // Just to keep track of occupied seats
    
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        if (seated.empty()) {
            seated.insert(0);
            return 0;
        }
        
        // Consider the maximum possible distance
        int maxDist = -1;
        int pos = -1;
        
        // Check starting gap if exists
        if (!seated.count(0)) {
            int first = *seated.begin();
            maxDist = first;
            pos = 0;
        }
        
        // Check intervals between seated students
        for (auto& p : intervals) {
            int dist = (p.second.second - p.second.first) / 2;
            int currPos = p.second.first + dist;
            if (dist > maxDist) {
                maxDist = dist;
                pos = currPos;
            }
        }
        
        // Check ending gap if exists
        if (!seated.count(N-1)) {
            int last = *seated.rbegin();
            int dist = N - 1 - last;
            if (dist > maxDist) {
                maxDist = dist;
                pos = N - 1;
            }
        }
        
        // Add new seat and update intervals
        seated.insert(pos);
        updateIntervals();
        return pos;
    }
    
    void leave(int p) {
        seated.erase(p);
        updateIntervals();
    }
    
private:
    void updateIntervals() {
        intervals.clear();
        if (seated.empty()) return;
        
        auto it = seated.begin();
        int prev = *it;
        ++it;
        
        // Add intervals between occupied seats
        for (; it != seated.end(); ++it) {
            int dist = (*it - prev) / 2;
            intervals.insert({dist, {prev, *it}});
            prev = *it;
        }
    }
};