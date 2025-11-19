// https://leetcode.com/problems/smallest-number-in-infinite-set

class SmallestInfiniteSet {
public:
    priority_queue<int> pq;
    map<int, int> m;
    int sm = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if (pq.empty()) {
            sm++;
            return sm - 1;
        } 
        int ret = pq.top();
        m[ret] = 0;
        pq.pop();
        return -ret;
    }
    
    void addBack(int num) {
        if (num < sm && m[num] == 0) {
            pq.push(-num);
            m[num] = 1;
        }

    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */