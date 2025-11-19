// https://leetcode.com/problems/word-ladder

class Solution {
public:
    const static int MXN = 5e3+1;
    vector<int> adj_list[MXN];

    bool areSimilar(string s1, string s2) {
        assert(s1.length() == s2.length());
        int count = 0;
        for (int i=0; i<s1.length(); i++)
            count += (s1[i] == s2[i]);
        return (count == s1.length() - 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);

        int N = (int)wordList.size();
        int endIndex = -1;
        for (int i=0; i<N; i++) {
            if (wordList[i] == endWord)
                endIndex = i;
        }
        if (endIndex == -1)
            return 0;

        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (areSimilar(wordList[i], wordList[j])) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }

        queue<int> q;
        vector<int> d(N, 0);

        d[N-1] = 1;
        q.push(N-1);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i : adj_list[x]) {
                if (!d[i]) {
                    q.push(i);
                    d[i] = d[x]+1;
                }
            }
        }

        return d[endIndex];
    }
};