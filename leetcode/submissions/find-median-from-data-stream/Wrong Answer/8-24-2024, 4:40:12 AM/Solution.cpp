// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    priority_queue<int> sm, lg;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if ((int)sm.size() < (int)lg.size()) 
            sm.push(num);
        else 
            lg.push(num);
    }
    
    double findMedian() {
        if ((int)sm.size() == (int)lg.size()) 
            return (1.0*sm.top() + lg.top())/2.0;
        return lg.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */