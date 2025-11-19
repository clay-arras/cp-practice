// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    priority_queue<int> sm;
    priority_queue<int, vector<int>, greater<int>> lg;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if ((int)sm.size() == (int)lg.size()) {
            if (!sm.empty() && num < sm.top()) {
                lg.push(sm.top());
                sm.pop();
                sm.push(num);
            } else {
                lg.push(num);
            }
        } else {
            if (!lg.empty() && num > lg.top()) {
                sm.push(lg.top());
                lg.pop();
                lg.push(num);
            } else {
                sm.push(num);
            }
        }
    }
    
    double findMedian() {
        if ((int)sm.size() == (int)lg.size()) 
            return (sm.top() + lg.top())*1.0/2.0;
        return lg.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


 /*

equal
- sm: pop to lg 
- lg: nothing

lg bigger
- sm: nothing
- lg: pop to sm
 */