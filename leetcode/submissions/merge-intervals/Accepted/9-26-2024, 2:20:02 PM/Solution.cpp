// https://leetcode.com/problems/merge-intervals

class disjointSet{
    public:
    vector<int> parent,size,inArray;
    disjointSet(int n){
        parent.resize(n,0);
        size.resize(n);
        inArray.resize(n,0);
        for (int i=0 ; i<n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    void markInArray(int n){
        inArray[n] = 1;
    }

    int find_set(int u){
        if (parent[u] == u) return u;
        return parent[u] = find_set(parent[u]);
    }

    void set_union(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if (a != b){
            if (a > b){
                swap(a,b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }

    vector<vector<int>> mergeIntervals(){
        vector<vector<int>> ans;
        for(int i=0 ; i<parent.size() ; i++){
            vector<int> temp;
            if (parent[i] == i && inArray[i] == 1){
                temp.push_back(i);
                temp.push_back(i + size[i] - 1);
                ans.push_back(temp);
            }
        }
        return ans;
    }

};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxNo = -1e8;
        for(vector<int> x: intervals){
            maxNo = max({maxNo , x[0] , x[1]});
        }
        
        disjointSet dj(maxNo + 1);

        for(vector<int> x: intervals){
            int st = x[0];
            int end = x[1];
            for(int i = st ; i<=end ; i++){
                dj.set_union(st,i);
                dj.markInArray(st);
                dj.markInArray(end);
            }
        }

        return dj.mergeIntervals();
    }
};