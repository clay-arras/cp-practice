// https://leetcode.com/problems/online-election

class TopVotedCandidate {
public:
    multiset<pair<int, int>> s; // {time, person_id}
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        multiset<pair<pair<int, int>, int>> cnt; // {cnt, time}, person_id
        unordered_map<int, decltype(cnt.begin())> m; // person_id to iterator

        int N = (int)persons.size();
        for (int i=0; i<N; i++) {
            if (!m.count(persons[i])) 
                m[persons[i]] = cnt.insert({{0, times[i]}, persons[i]});

            auto it = m[persons[i]];
            int val = it->first.first + 1;
            cnt.erase(it);
            m[persons[i]] = cnt.insert({{val, times[i]}, persons[i]});

            s.insert({times[i], cnt.rbegin()->second});
        }
    }
    
    int q(int t) {
        auto it = s.lower_bound({t, INT_MAX});
        assert(it != s.begin());
        it = prev(it);
        return it->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */