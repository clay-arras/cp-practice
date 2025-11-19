// https://leetcode.com/problems/stock-price-fluctuation

class StockPrice {
public:
    map<int, int> m; // time, val
    priority_queue<pair<int, int>> mn, mx; // {val, time}

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        m[timestamp] = price;
        mn.push({-price, timestamp});
        mx.push({price, timestamp});
    }
    
    int current() {
        return m.rbegin()->second;
    }
    
    int maximum() {
        while (m[mx.top().second] != mx.top().first)
            mx.pop();
        return mx.top().first;
    }
    
    int minimum() {
        while (m[mn.top().second] != -mn.top().first)
            mn.pop();
        return -mn.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */


/*

// segtree over 1e5

2 heaps, min + max, lazy deletion
{val, timestamp} -> for lazy deletion, check match in hashmap

time complexity: logN
space complexity: N

*/