// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:
    vector<Trie*> pt;
    bool en = false;
    Trie() { pt = vector<Trie*>(26, nullptr); }
    auto insert(string s) {
        if (s.empty()) return (en = true);
        if (pt[s[0]-'a'] == nullptr) {
            Trie* t = new Trie();
            pt[s[0]-'a'] = t;
        }
        return pt[s[0]-'a']->insert(s.substr(1));
    }
    bool search(string s) {
        if (s.empty()) return en;
        if (pt[s[0]-'a'] == nullptr)
            return false;
        return pt[s[0]-'a']->search(s.substr(1));
    }
    bool startsWith(string s) {
        if (s.empty()) return true;
        if (pt[s[0]-'a'] == nullptr)
            return false;
        return pt[s[0]-'a']->startsWith(s.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */