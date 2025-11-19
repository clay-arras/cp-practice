// https://leetcode.com/problems/wiggle-subsequence

class Solution:
    def wiggleMaxLength(self, arr: List[int]) -> int:
        @cache
        def solve_rec(idx: int, inc: bool) -> list[int]:
            curr = arr[idx]
            ans = []
    
            if idx == 0:
                return [curr]
    
            if (arr[idx - 1] < curr and inc) or (arr[idx - 1] > curr and not inc):
                x = solve_rec(idx - 1, not inc)
                x.append(curr)
                ans = x if len(x) > len(ans) else ans
            else:
                x = solve_rec(idx - 1, inc)
                ans = x if len(x) > len(ans) else ans
    
            return ans
    
        x = solve_rec(len(arr)-1, True)
        y = solve_rec(len(arr)-1, False)
    
        return max(len(x), len(y))
            