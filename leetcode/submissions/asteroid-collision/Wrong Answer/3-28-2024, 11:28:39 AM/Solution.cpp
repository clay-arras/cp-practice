// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int N = (int)asteroids.size();

        int count = 0;
        while (count < N && asteroids[count] < 0) {
            st.push(asteroids[count]);
            count++;
        }

        for (int i=count; i<N; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() > 0) {
                    if (st.top() > abs(asteroids[i])) {
                        break;
                    } else if (st.top() < abs(asteroids[i])) {
                        st.pop();
                    } else {
                        st.pop();
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};