// https://leetcode.com/problems/reformat-phone-number

class Solution:
    def reformatNumber(self, number: str) -> str:
        number = number.replace(" ", "")
        number = number.replace("-", "")

        arr = []
        while len(number) > 4:
            arr.append(number[0:3])
            number = number[3:]

        print(number)

        if len(number) == 4:
            arr.append(number[0:2])
            arr.append(number[2:])
        else:
            arr.append(number)
        return "-".join(arr)
        