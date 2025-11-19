// https://leetcode.com/problems/two-sum-iii-data-structure-design

class TwoSum:
    def __init__(self):
        self.numbers = []
        self.hashmap = defaultdict(lambda: 0)

    def add(self, number: int) -> None:
        self.numbers.append(number)
        self.hashmap[number] += 1

    def find(self, value: int) -> bool:
        for i in self.numbers:
            if 2 * i == value and self.hashmap[value - i] >= 2:
                return True
            elif 2 * i != value and self.hashmap[value - i] >= 1:
                return True
        return False
        


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)