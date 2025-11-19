// https://leetcode.com/problems/select-cells-in-grid-with-maximum-score

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* left;  // 0
    Node* right; // 1
};

class Solution {
public:
    Node* root;
    Solution() { root = new Node(); }
    void insert(int n) {
        Node* temp = root;
        for (int i = 31; i >= 0; i--) {
            int currentBit = (n >> i) & 1;
            if (!currentBit) {
                if (!temp->left)
                    temp->left = new Node();
                temp = temp->left;
            }
            else {
                if (!temp->right)
                    temp->right = new Node();
                temp = temp->right;
            }
        }
    }

    // O(1) loop
    int helper(int val) {
        int ans = 0;
        Node* temp = root;

        // 0 -> move right; else vice versa
        for (int i = 31; i >= 0; i--) {
            int currentBit = (val >> i) & 1;

            if (!currentBit) {
                if (temp->right) {
                    temp = temp->right;
                    ans += (1 << i);
                } else
                    temp = temp->left;

            } else {
                if (temp->left) {
                    temp = temp->left;
                    ans += (1 << i);
                } else
                    temp = temp->right;
            }
        }

        return ans;
    }

    // O(n)
    int findMaximumXOR(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int value = arr[i];
            insert(value);
            int curAns = helper(value);
            res = max(curAns, res);
        }
        return res;
    }
};

int main() {
    int arr[] = {14, 70, 53, 33, 49, 91, 36, 80, 92, 51, 66, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution s;

    vector<int> v(arr, arr + n);
    cout << s.findMaximumXOR(v);

    return 0;
}