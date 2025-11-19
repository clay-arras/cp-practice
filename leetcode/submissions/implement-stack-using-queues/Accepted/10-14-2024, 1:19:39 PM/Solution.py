// https://leetcode.com/problems/implement-stack-using-queues

from collections import deque

class MyStack:
    def __init__(self):
        self.main_queue = deque()
        self.temp_queue = deque()

    def push(self, value: int) -> None:
        prev_queue_size = len(self.main_queue)
        self.main_queue.append(value)

        for i in range(prev_queue_size):
            topVal = self.main_queue.popleft()
            self.main_queue.append(topVal)

    def pop(self) -> int:
        if self.empty():
            raise Exception("No elements in the stack")
        return self.main_queue.popleft()

    def top(self) -> int:
        return self.main_queue[0]

    def empty(self) -> bool:
        return len(self.main_queue) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()