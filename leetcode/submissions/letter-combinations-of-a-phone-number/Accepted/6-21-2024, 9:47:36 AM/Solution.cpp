// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> ans;
    void solve(string digits, string sol) {
        if (digits == "") {
            ans.push_back(sol);
            return;
        }
        string rem = digits.substr(1);
        switch (digits[0]) {
            case '2':
                solve(rem, sol + 'a');
                solve(rem, sol + 'b');
                solve(rem, sol + 'c');
                break;
            case '3':
                solve(rem, sol + 'd');
                solve(rem, sol + 'e');
                solve(rem, sol + 'f');
                break;
            case '4':
                solve(rem, sol + 'g');
                solve(rem, sol + 'h');
                solve(rem, sol + 'i');
                break;
            case '5':
                solve(rem, sol + 'j');
                solve(rem, sol + 'k');
                solve(rem, sol + 'l');
                break;
            case '6':
                solve(rem, sol + 'm');
                solve(rem, sol + 'n');
                solve(rem, sol + 'o');
                break;
            case '7':
                solve(rem, sol + 'p');
                solve(rem, sol + 'q');
                solve(rem, sol + 'r');
                solve(rem, sol + 's');
                break;
            case '8':
                solve(rem, sol + 't');
                solve(rem, sol + 'u');
                solve(rem, sol + 'v');
                break;
            case '9':
                solve(rem, sol + 'w');
                solve(rem, sol + 'x');
                solve(rem, sol + 'y');
                solve(rem, sol + 'z');
                break;
        }
    }

    vector<string> letterCombinations(string digits) {
        solve(digits, "");
        return digits == "" ? vector<string>() : ans; 
    }
};