// https://leetcode.com/problems/most-visited-sector-in-a-circular-track

class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        ans = []

        for i in range(rounds[0], rounds[-1]+1):
            ans.append(i)

        return ans
