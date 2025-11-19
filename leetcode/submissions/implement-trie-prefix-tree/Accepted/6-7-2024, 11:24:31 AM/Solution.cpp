// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:
    vector<Trie*> pt;
    bool isEnd;
    Trie() {
        pt = vector<Trie*>(26, nullptr);
        isEnd = false;
    }
    
    void insert(string word) {
        if (word.empty()) {
            isEnd = true;
            return;
        }
        if (pt[word[0] - 'a'] == nullptr) {
            Trie* t = new Trie();
            pt[word[0] - 'a'] = t;
        }
        pt[word[0] - 'a']->insert(word.substr(1));
    }

    
    bool search(string word) {
        if (word.empty()) return isEnd;
        if (pt[word[0] - 'a'] == nullptr) 
            return false;
        return pt[word[0] - 'a']->search(word.substr(1));
    }
    
    bool startsWith(string prefix) {
        if (prefix.empty()) return true;
        if (pt[prefix[0] - 'a'] == nullptr) 
            return false;
        return pt[prefix[0] - 'a']->startsWith(prefix.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */