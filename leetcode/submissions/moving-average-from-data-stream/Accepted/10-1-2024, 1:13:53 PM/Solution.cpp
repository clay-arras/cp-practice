// https://leetcode.com/problems/moving-average-from-data-stream

class MovingAverage {
public:
    int N, sum;
    queue<int> q;
    MovingAverage(int size) {
        sum = 0;
        N = size; 
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (q.size() > N) {
            sum -= q.front();
            q.pop();
        }
        return sum * 1.0/(int)q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */