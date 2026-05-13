class Solution {
public:
    vector<string> res;
    unordered_map<char, string> digitToChar = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtrack(int i, string curStr, string& digits) {
        if (curStr.length() == digits.length()) {
            res.push_back(curStr);
            return;
        }

        for (char c : digitToChar[digits[i]]) {
            backtrack(i + 1, curStr + c, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (!digits.empty()) {
            backtrack(0, "", digits);
        }

        return res;
    }
};
