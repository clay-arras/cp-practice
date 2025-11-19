// https://leetcode.com/problems/wiggle-subsequence

class Solution:    
    def wiggleMaxLength(self, nums: List[int]) -> int:
        def update_ans(ans, x):
            return x if len(x) > len(ans) else ans

        @cache
        def solve_rec(idx: int, inc: bool) -> list[int]:
            """
            dp[arr][inc] is the longest zigzag array you can form using arr and the CURR
            zigzag should be inc / dec (i.e. the next value should be LESS than curr)
            """
            curr = nums[idx]
            ans = []

            if idx == 0:
                return [curr]

            if nums[idx - 1] < curr and inc:
                x = solve_rec(idx - 1, not inc)
                x.append(curr)
                ans = update_ans(ans, x)
            elif nums[idx - 1] > curr and not inc:
                x = solve_rec(idx - 1, not inc)
                x.append(curr)
                ans = update_ans(ans, x)
            else:
                x = solve_rec(idx - 1, inc)
                ans = update_ans(ans, x)

            return ans

        x = solve_rec(len(nums)-1, True)
        y = solve_rec(len(nums)-1, False)
        return max(len(x), len(y))