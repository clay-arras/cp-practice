// https://leetcode.com/problems/search-suggestions-system

class Solution {
public:
    struct Trie {
        vector<Trie*> pt;
        vector<string> hold;
        bool en = false;
        Trie() { pt = vector<Trie*>(26, nullptr); }
        auto insert(string s, string orig) {
            hold.push_back(orig);
            if (s.empty()) return (en = true);
            if (pt[s[0]-'a'] == nullptr) {
                Trie* t = new Trie();
                pt[s[0]-'a'] = t;
            }
            return pt[s[0]-'a']->insert(s.substr(1), orig);
        }
        vector<string> search(string s) {
            if (s.empty()) {
                vector<string> ans;
                sort(hold.begin(), hold.end());
                for (int i=0; i<min(3, (int)hold.size()); i++)
                    ans.push_back(hold[i]);
                return ans;
            }
            if (pt[s[0]-'a'] == nullptr)
                return {};
            return pt[s[0]-'a']->search(s.substr(1));
        }
    };

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        vector<vector<string>> ans;
        for (string s : products)
            t.insert(s, s);
        
        string s = "";
        s += searchWord[0];
        for (int i=0; i<(int)searchWord.size(); i++, s+=searchWord[i]) {
            ans.push_back(t.search(s));
        }
        
        return ans;
    }
};