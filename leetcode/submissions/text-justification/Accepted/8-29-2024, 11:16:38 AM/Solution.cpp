// https://leetcode.com/problems/text-justification

class Solution {
public:
    int firstTrue(int l, int r, function<bool(int)> f) {
        r++;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    string ns(int i) {
        string s = "";
        for (int j=0; j<i; j++)
            s += " ";
        return s;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int N = (int)words.size();

        for (int i=0; i<N; ) {
            int sum = 0;
            vector<string> arr;
            while (i < N && sum + (int)words[i].size() + (int)arr.size() <= maxWidth) {
                sum += (int)words[i].size();
                arr.push_back(words[i]);
                i++;
            }
            string s = "";
            int sp = (int)arr.size()-1;
            if (!sp || i == N) {
                for (int j=0; j<(int)arr.size(); j++) {
                    if (j) 
                        s += " ";
                    s += arr[j];
                }
                s += ns(maxWidth - (sum + (int)arr.size() - 1));
                ans.push_back(s);
                continue;
            }

            int mn = floor((maxWidth - sum)*1.0/ sp);
            int mx = ceil((maxWidth - sum)*1.0/ sp);
            auto ok = [&](int k) {    
                return (k*mx + (sp-k)*mn)+sum >= maxWidth;
            };

            int val = firstTrue(0, sp, ok);
            for (int i=0; i<(int)arr.size(); i++) {
                if (i) {
                    s += ns(mn);
                    if (i <= val)
                        s += " ";
                }
                s += arr[i];
            }

            ans.push_back(s);
        } 

        return ans;
    }
};