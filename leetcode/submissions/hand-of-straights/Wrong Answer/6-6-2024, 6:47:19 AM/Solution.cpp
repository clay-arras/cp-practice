// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ((int)hand.size() % groupSize) return false;
        sort(hand.begin(), hand.end());

        for (auto i : hand)
            cout << i << " ";
        cout << endl;

        vector<int> arr((int)hand.size() / groupSize, 0);
        int ptr = 0;
        arr[0]++;
        for (int i=1; i<(int)hand.size(); i++) {
            if (hand[i-1]+1 == hand[i]) {
                arr[ptr]++;
                if (arr[ptr] == groupSize) ptr++;
            } 
            while (hand[i-1] == hand[i]) {
                arr[ptr]++;
                if (arr[ptr] == groupSize) ptr++;
                i++;
            }
        }
        cout << ptr << endl;
        return (ptr == (int)hand.size() / groupSize - 1);
    }
};