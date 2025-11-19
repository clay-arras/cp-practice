// https://leetcode.com/problems/smallest-number-in-infinite-set

class SmallestInfiniteSet {
public:
    priority_queue<int> pq;
    int sm = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if (pq.empty()) {
            sm++;
            return sm - 1;
        } 
        int ret = pq.top();
        pq.pop();
        return ret;
    }
    
    void addBack(int num) {
        if (num < sm) 
            pq.push(num);

    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */