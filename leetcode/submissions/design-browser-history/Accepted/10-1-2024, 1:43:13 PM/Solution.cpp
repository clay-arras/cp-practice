// https://leetcode.com/problems/design-browser-history

class BrowserHistory {
public:
    vector<string> h;
    int sz = 1, pt = 0;
    BrowserHistory(string homepage) {
        h.push_back(homepage);
    }
    
    void visit(string url) {
        if (pt+1 < (int)h.size()) {
            pt++;
            h[pt] = url;
            sz = pt + 1;
        } else {
            h.push_back(url);
            pt++;
            sz = pt + 1;
        }
    }
    
    string back(int steps) {
        pt = max(0, pt - steps);
        return h[pt];
    }
    
    string forward(int steps) {
        pt = min(sz-1, pt + steps);
        return h[pt];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */