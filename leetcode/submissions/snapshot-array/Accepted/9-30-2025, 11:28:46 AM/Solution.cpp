// https://leetcode.com/problems/snapshot-array

class SnapshotArray { 
private:
    int lastTrue(int l, int r, function<bool(int)> ok) {
        l--;
        for (int diff=r-l; diff>0; diff/=2) 
            while (l + diff <= r && ok(l + diff))
                l += diff;
        return l;
    }

    vector<vector<pair<int, int>>> data; // O(totalCalls)
    int sn = 0;

public:
    SnapshotArray(int length) {
        data = vector<vector<pair<int, int>>> (length, vector<pair<int, int>>(1, {-1, 0}));
    } 
    void set(int index, int val) {
        data[index].push_back({sn, val});
    }
    int snap() {
        return sn++;
    }
    int get(int index, int snap_id) {
        int l = 0;
        int r = data[index].size()-1;
        
        int idx = lastTrue(l, r, [&](int t) {
            return data[index][t].first <= snap_id;
        });
        return data[index][idx].second;
    }
};


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */