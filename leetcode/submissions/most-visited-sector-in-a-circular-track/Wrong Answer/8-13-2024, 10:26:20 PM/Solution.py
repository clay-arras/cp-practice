// https://leetcode.com/problems/most-visited-sector-in-a-circular-track

class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        ans = []

        for i in range(n):
            val = ((rounds[0] + i-1) % n)+1
            ans.append(val)
            if val is rounds[-1]:
                break

        return ans
