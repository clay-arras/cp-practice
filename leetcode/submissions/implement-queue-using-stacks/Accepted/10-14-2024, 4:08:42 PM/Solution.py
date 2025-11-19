// https://leetcode.com/problems/implement-queue-using-stacks

"""Implements a queue with stacks, can support all queue operations

Typical usage example:
    my_queue = MyQueue()
    my_queue.push(9)
    my_queue.push(3)
    my_queue.pop()      # returns 9
"""

from collections import deque


class MyQueue:
    def __init__(self) -> None:
        self.push_stack = deque()
        self.pop_stack = deque()

    def push(self, value: int) -> None:
        self.push_stack.append(value)
    
    def pop(self) -> int:
        if len(self.pop_stack) == 0:
            self.transfer()
        if len(self.pop_stack) == 0:
            raise IndexError("Empty Stack")
        return self.pop_stack.pop()
    
    def peek(self) -> int:
        if len(self.pop_stack) == 0:
            self.transfer()
        if len(self.pop_stack) == 0:
            raise IndexError("Empty Stack")
        return self.pop_stack[-1]

    def transfer(self) -> None:
        while len(self.push_stack) != 0:
            top = self.push_stack.pop()
            self.pop_stack.append(top)
    
    def empty(self) -> bool:
        return len(self.pop_stack) + len(self.push_stack) == 0