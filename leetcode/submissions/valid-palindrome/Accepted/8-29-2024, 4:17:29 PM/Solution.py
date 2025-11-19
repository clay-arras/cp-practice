// https://leetcode.com/problems/valid-palindrome

class Solution:
    def isPalindrome(self, s: str) -> bool:
        stripped_string = [char.lower() for char in s if char.isalnum()]
        print(stripped_string)

        # for index in range(len(stripped_string)):
        #     if stripped_string[index] == stripped_string[-index-1]

        return all(map(lambda index : stripped_string[index] == stripped_string[-index - 1], range(len(stripped_string))))
