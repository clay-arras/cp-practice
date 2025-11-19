// https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum

class Solution:
    def countStableSubarrays(self, capacity: List[int]) -> int:
        N = len(capacity)

        pref = 0
        ans = 0

        m = defaultdict(lambda: [])
        for i in range(N):
            l = m[(capacity[i], pref - 2*capacity[i])]
            cnt = 0

            for j in range(len(l)-1, -1, -1):
                if i+1 - l[j] >= 3:
                    break;
                cnt += 1
            ans += len(l) - cnt;

            m[(capacity[i], pref)].append(i)
            pref += capacity[i]

        return ans