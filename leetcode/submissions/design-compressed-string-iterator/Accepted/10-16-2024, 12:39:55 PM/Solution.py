// https://leetcode.com/problems/design-compressed-string-iterator

"""Design and implement a data structure for a compressed string iterator. The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

Implement the StringIterator class:

    next() Returns the next character if the original string still has uncompressed characters, otherwise returns a white space.
    hasNext() Returns true if there is any letter needs to be uncompressed in the original string, otherwise returns false.
"""
from typing import List


class StringIterator:
    def __init__(self, compressed_string: str) -> None:
        self.compressed_string: str = compressed_string
        self.decompressed_string_list: List[tuple[int, str]] = []

        while len(compressed_string) != 0:
            index = 1
            num_str = ""
            while index < len(compressed_string) and compressed_string[index].isdigit():
                num_str += compressed_string[index]
                index += 1

            self.decompressed_string_list.append(
                (int(num_str), compressed_string[0])
            )
            compressed_string = compressed_string[index :]

    def next(self) -> str:
        if not self.hasNext():
            return " "
        current_group = self.decompressed_string_list[0]
        return_char = current_group[1]
        self.decompressed_string_list[0] = (current_group[0] - 1, current_group[1])
        if self.decompressed_string_list[0][0] == 0:
            self.decompressed_string_list = self.decompressed_string_list[1:]
        return return_char

    def hasNext(self) -> bool:
        return bool(self.decompressed_string_list)

    def _verify_string(self, compressed_str: str) -> bool:
        pass