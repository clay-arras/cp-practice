// https://leetcode.com/problems/decode-string

class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
        for c in s:
            stack.append(c)
            if c == ']':

                substr = ""
                while len(stack) and stack[-1] not in nums:
                    substr += stack[-1]
                    stack.pop()
                substr = substr[1:-1:][::-1]

                num = ""
                while len(stack) and stack[-1] in nums:
                    num += stack[-1]
                    stack.pop()
                num = int(num[::-1])

                for i in num * substr:
                    stack.append(i)
        
        return ''.join(stack)

        