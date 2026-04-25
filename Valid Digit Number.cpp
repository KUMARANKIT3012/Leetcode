class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        char ch = x + '0';

        if (s[0] == ch) return false;

        if (s.find(ch) != string::npos) return true;

        return false;
    }
};
