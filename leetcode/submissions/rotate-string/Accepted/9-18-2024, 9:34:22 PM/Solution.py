// https://leetcode.com/problems/rotate-string

class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        shifted = s
        for _ in range(len(s)):
            if goal == shifted:
                return True
            else:
                shifted += shifted[0]
                shifted = shifted[1:] 
        return False