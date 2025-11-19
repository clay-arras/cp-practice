// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    using wordFreq = pair<int, string>;
    vector<string> topKFrequent(vector<string>& words, int k) {
        int N = (int)words.size();

        unordered_map<string, int> cnt;
        for (auto w : words) 
            cnt[w]++;
        
        vector<wordFreq> cont;
        for (auto [k, v] : cnt)
            cont.push_back({v, k});

        auto comp = [](const wordFreq& a, const wordFreq& b) {
            if (a.first == b.first)
                return a.second >= b.second;
            return a.first < b.first;
        };
        priority_queue<wordFreq, vector<wordFreq>, decltype(comp)> pq (cont.begin(), cont.end());

        vector<string> ans;
        while (k--) {
            string s = pq.top().second;
            ans.push_back(s);
            pq.pop();
        }
        return ans;
    }
};
/*
{
    "i": 2
    "love": 2
    "leecode": 1
    "coding": 1
}
pair<int, string> {2, "i"} 

write custom comparator:
operator<(const pair<int, string>& a, const pair<int, string>& b) ...

take first k elements of that list

---

time complexity: O(N + klogN)
space complexity: O(N)






Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
*/