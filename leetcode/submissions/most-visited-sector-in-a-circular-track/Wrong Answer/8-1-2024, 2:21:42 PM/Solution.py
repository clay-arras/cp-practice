// https://leetcode.com/problems/most-visited-sector-in-a-circular-track

class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        diff = [0]*(n+1)
        rounds = [i - 1 for i in rounds]
        diff[rounds[0]] -= 1
        diff[rounds[0]+1] += 1
        for i in range(len(rounds)-1):
            if rounds[i] < rounds[i+1]:
                diff[rounds[i]+1] -= 1
                diff[rounds[i+1]+1] += 1
            elif rounds[i] > rounds[i+1]:
                diff[rounds[i]+1] += 1
                diff[rounds[i+1]+1] -= 1
        
        arr = [0]*(n+1)
        for i in range(n):
            arr[i+1] = arr[i] - diff[i+1]
        print(arr)

        return diff
                






















        