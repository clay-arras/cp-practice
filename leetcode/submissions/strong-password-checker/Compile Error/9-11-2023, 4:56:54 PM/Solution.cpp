// https://leetcode.com/problems/strong-password-checker

class Solution {
public:
    int strongPasswordChecker(string password) {
        
    }
};



// aaaa - 1
// bbbaaa - 2
// bbbbbaaa - 3
// bbbbaaabbb

// bbabbabbabb
// 7 - 3
// 6 - 2
// 5 - 2 bbabbabb
// 4 - 1
// 3 - 1
// tot += cnsc / 2

// adds:
// ext + 1 if not lowercase, not uppercase, not digit
// num_needed = max(tot, ext)

// min(abs(str.length() - 6), abs(str.length() - 20))
// after: decide add or remove


// if len > 20
// trim first then replace
// bbbbbaaabbbbbb - 3 1 4 = 8
// 14
// down to 7