// https://leetcode.com/problems/all-oone-data-structure

class AllOne {
public:
    list<pair<int, unordered_set<string>>> ls;
    unordered_map<string, decltype(ls.begin())> m;

    AllOne() {
        ls.push_back({0, {""}});
    }
    
    void inc(string key) {
        cout << "inc: " << key << endl;

        if (!m.count(key)) {
            ls.begin()->second.insert(key); 
            m[key] = ls.begin();
        }

        auto it = m[key];
        if (next(it) == ls.end() || next(it)->first != it->first + 1) 
            ls.insert(next(it), {it->first + 1, {}});

        next(it)->second.insert(key);
        m[key] = next(it);

        it->second.erase(key);    
        if (it->second.empty())
            ls.erase(it);

        for (auto i : ls) {
            cout << i.first << ": ";
            for (string s : i.second)
                cout << s << " ";
            cout << endl;
        }
        cout << endl;
    }
    
    void dec(string key) {
        cout << "dec: " << key << endl;
        auto it = m[key];
        if (prev(it)->first != it->first - 1) 
            ls.insert(it, {it->first - 1, {}});

        prev(it)->second.insert(key);
        m[key] = prev(it);

        it->second.erase(key);    
        if (it->second.empty())
            ls.erase(it);

        for (auto i : ls) {
            cout << i.first << ": ";
            for (string s : i.second)
                cout << s << " ";
            cout << endl;
        }
        cout << endl;
    }
    
    string getMaxKey() {
        auto it = ls.rbegin();
        if (it->first == 0)
            return "";
        return *it->second.begin();
    }
    
    string getMinKey() {
        auto it = ls.begin();
        if (next(it) == ls.end())
            return "";
        advance(it, 1);
        return *it->second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */