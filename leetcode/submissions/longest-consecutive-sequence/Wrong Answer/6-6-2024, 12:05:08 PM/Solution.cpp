// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    struct DSU {
        map<int, int> e;
        void init() { 
            e = map<int, int>();
        }
        int get(int x) {
            if (e[x] < 0)
                return x;
            return e[x] = get(e[x]);
        }
        int size(int x) {
            return -e[get(x)];
        }
        bool unite(int x, int y) {
            x = get(x), y = get(y);
            if (x == y)
                return 0;
            if (e[x] > e[y])
                swap(x,y);
            e[x] += e[y];
            e[y] = x;
            return 1;
        }
    };

    int longestConsecutive(vector<int>& nums) {
        DSU d; d.init();
        for (auto i : nums)
            d.e[i] = -1;

        int maxNum = 0;
        for (auto i : nums) {
            if (d.e.count(i+1))
                d.unite(i, i+1);
            if (d.e.count(i-1))
                d.unite(i, i-1);
            maxNum = max(maxNum, d.size(i));

        }
        for (auto [k, v] : d.e) 
            cout << k << " " << v << endl;
        
        return maxNum;
    }
};