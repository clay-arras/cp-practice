// https://leetcode.com/problems/decode-string

class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for c in s:
            stack.append(c)
            if (c == ']'):
                substr = ""
                while (stack[-1] != '['):
                    substr += stack[-1]
                    stack.pop()
                substr += stack[-1]
                stack.pop()
                substr = substr[1:-1:][::-1]
                num = int(stack[-1])
                stack.pop()
                for i in num * substr:
                    stack.append(i)
        return ''.join(stack)

        