// https://leetcode.com/problems/maximum-xor-score-subarray-queries

class Solution {
public:
    int xorScore(vector<int> a) {
        int N = (int)a.size();
        for (int i = 1; i < N; i++)
            for (int j = N - 1; j >= i; j--)
                a[j] = a[j] ^ a[j - 1];
        return a[N - 1];
    }

    struct Trie {
        vector<Trie*> pt;
        bool en = false;
        Trie() { pt = vector<Trie*>(2, nullptr); }
        auto insert(string s) {
            if (s.empty())
                return (en = true);
            if (pt[s[0] - '0'] == nullptr) {
                pt[s[0] - '0'] = new Trie();
            }
            return pt[s[0] - '0']->insert(s.substr(1));
        }
        int search(string s, int i) {
            if (s.empty() || i == 0)
                return 0;
            if (s[0] - '0' == 0 && pt[1] != nullptr)
                return (1 << i) + pt[1]->search(s.substr(1), i - 1);
            if (s[0] - '0' == 1 && pt[0] != nullptr)
                return (1 << i) + pt[0]->search(s.substr(1), i - 1);
            if (pt[0] != nullptr)
                return pt[0]->search(s.substr(1), i - 1);
            if (pt[1] != nullptr)
                return pt[1]->search(s.substr(1), i - 1);
            return 0;
        }
    };

    string ston(int i) {
        bitset<32> b(i);
        return b.to_string();
    }

    // class Node {
    // public:
    //     Node* left;  // 0
    //     Node* right; // 1
    // };

    // class MXOR {
    // public:
    //     Node* root;
    //     MXOR() { root = new Node(); }
    //     void insert(int n) {
    //         Node* temp = root;
    //         for (int i = 31; i >= 0; i--) {
    //             int currentBit = (n >> i) & 1;
    //             if (!currentBit) {
    //                 if (!temp->left)
    //                     temp->left = new Node();
    //                 temp = temp->left;
    //             } else {
    //                 if (!temp->right)
    //                     temp->right = new Node();
    //                 temp = temp->right;
    //             }
    //         }
    //     }

    //     int helper(int val) {
    //         int ans = 0;
    //         Node* temp = root;

    //         for (int i = 31; i >= 0; i--) {
    //             int currentBit = (val >> i) & 1;

    //             if (!currentBit) {
    //                 if (temp->right) {
    //                     temp = temp->right;
    //                     ans += (1 << i);
    //                 } else
    //                     temp = temp->left;

    //             } else {
    //                 if (temp->left) {
    //                     temp = temp->left;
    //                     ans += (1 << i);
    //                 } else
    //                     temp = temp->right;
    //             }
    //         }

    //         return ans;
    //     }

    //     // O(n)
    //     int findMaximumXOR(vector<int>& arr) {
    //         int n = arr.size();
    //         int res = 0;
    //         for (int i = 0; i < n; i++) {
    //             int value = arr[i];
    //             insert(value);
    //             int curAns = helper(value);
    //             res = max(curAns, res);
    //         }
    //         return res;
    //     }
    // };

    class Node {
    public:
        Node* one;
        Node* zero;
    };

    class trie {
        Node* root;

        public:
        trie() { root = new Node(); }

        void insert(int n) {
            Node* temp = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (n >> i) & 1;
                if (bit == 0) {
                    if (temp->zero == NULL) {
                        temp->zero = new Node();
                    }
                    temp = temp->zero;
                } else {
                    if (temp->one == NULL) {
                        temp->one = new Node();
                    }
                    temp = temp->one;
                }
            }
        }

        int helper(int value) {
            Node* temp = root;
            int current_ans = 0;

            for (int i = 31; i >= 0; i--) {
                int bit = (value >> i) & 1;
                if (bit == 0) {
                    if (temp->one) {
                        temp = temp->one;
                        current_ans += (1 << i);
                    } else {
                        temp = temp->zero;
                    }
                } else {
                    if (temp->zero) {
                        temp = temp->zero;
                        current_ans += (1 << i);
                    } else {
                        temp = temp->one;
                    }
                }
            }
            return current_ans;
        }

        int max_xor(int arr[], int n) {
            int max_val = 0;
            insert(arr[0]);
            for (int i = 1; i < n; i++) {
                max_val = max(helper(arr[i]), max_val);
                insert(arr[i]);
            }
            return max_val;
        }
    };

    vector<int> maximumSubarrayXor(vector<int>& nums,
                                   vector<vector<int>>& queries) {
        vector<int> ans;
        int N = (int)nums.size();
        for (auto q : queries) {
            trie* t = new trie();
            // MXOR* t = new MXOR();
            int mx = 0;
            t->insert(q[0]);
            for (int i = q[0]+1; i <= q[1]; i += 2) {
                mx = max(mx, t->helper(nums[i]));
                t->insert(nums[i]);
            }
            t = new trie();
            t->insert(nums[q[0]] ^ nums[q[0]+1]);
            for (int i = q[0] + 2; i <= q[1]; i += 2) {
                mx = max(mx, t->helper(nums[i] ^ nums[i - 1]));
                t->insert(nums[i] ^ nums[i - 1]);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};