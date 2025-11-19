// https://leetcode.com/problems/exam-room

class ExamRoom {
public:
    set<int> seats;
    int N;
    
    void printState(string msg) {
        cout << "\n=== " << msg << " ===\n";
        cout << "Occupied seats: ";
        for(int seat : seats) {
            cout << seat << " ";
        }
        cout << "\n\n";
    }
    
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        printState("Before seat");
        
        if (seats.empty()) {
            seats.insert(0);
            printState("After seat (empty)");
            return 0;
        }
        
        int maxDist = *seats.begin();  // Distance to start
        int pos = 0;
        
        // Find largest gap
        auto prev = seats.begin();
        for(auto it = next(seats.begin()); it != seats.end(); it++) {
            int dist = (*it - *prev) / 2;
            if (dist > maxDist) {
                maxDist = dist;
                pos = *prev + dist;
            }
            prev = it;
        }
        
        // Check distance to end
        if (N - 1 - *seats.rbegin() > maxDist) {
            pos = N - 1;
        }
        
        seats.insert(pos);
        printState("After seat");
        return pos;
    }
    
    void leave(int p) {
        printState("Before leave " + to_string(p));
        seats.erase(p);
        printState("After leave");
    }
};