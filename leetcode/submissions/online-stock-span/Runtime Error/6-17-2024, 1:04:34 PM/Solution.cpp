// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    stack<pair<int, int>> s;
    int cnt = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        pair<int, int> x = {-1, cnt};
        while (!s.empty() && s.top().first <= price) {
            s.pop();
            x = s.top();
        }

        cnt++;
        s.push({price, cnt});
        return cnt - x.second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */