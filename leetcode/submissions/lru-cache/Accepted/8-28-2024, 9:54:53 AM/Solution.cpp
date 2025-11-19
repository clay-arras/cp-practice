// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    map<int, int> count, m;
    queue<int> q;
    int k;
    LRUCache(int capacity) {
        k = capacity;
    }
    
    int get(int key) {
        if (count[key]) {
            q.push(key);
            count[key]++;
            return m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        m[key] = value;
        if (!count[key]) 
            k--;
        count[key]++;
        q.push(key);
        while (k < 0) {
            count[q.front()]--;
            if (!count[q.front()])
                k++;
            q.pop();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */