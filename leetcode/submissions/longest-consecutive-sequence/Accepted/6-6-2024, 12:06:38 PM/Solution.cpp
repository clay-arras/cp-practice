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

    const int N = 1e9+1;
    int longestConsecutive(vector<int>& nums) {
        DSU d; d.init();
        for (auto i : nums)
            d.e[i+N] = -1;

        int maxNum = 0;
        for (auto i : nums) {
            if (d.e.count(i+1+N))
                d.unite(i+N, i+1+N);
            if (d.e.count(i-1+N))
                d.unite(i+N, i-1+N);
            maxNum = max(maxNum, d.size(i+N));

        }
        
        return maxNum;
    }
};