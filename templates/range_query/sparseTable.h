template<class T>
struct RMQ {
    vector<T> v; vector<vector<int>> jmp;
    int level(int x) { return 31-__builtin_clz(x); }
    int cmb(int a, int b) {
        if (v[a] == v[b])
            return min(a, b);
        return v[a] < v[b] ? a : b;
    }
    void init(const vector<T>& _v) {
        int sz = (int)_v.size();
        jmp = { vector<int>(sz) };
        v = _v;
        iota(jmp[0].begin(), jmp[0].end(), 0);
        for (int j=1; (1<<j)<=sz; j++) {
            jmp.push_back(vector<int>(sz-(1<<j)+1));
            for (int i=0; i<(int)jmp[j].size(); i++)
                jmp[j][i] = cmb(jmp[j-1][i], jmp[j-1][i+(1<<(j-1))]);
        }
    }
    int index(int l, int r) {
        int d = level(r-l+1);
        assert(l <= r);
        return cmb(jmp[d][l], jmp[d][r-(1<<d)+1]);
    }
    T query(int l, int r) { return v[index(l,r)]; }
};