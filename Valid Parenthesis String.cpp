// optimal way is by DP toh revisit this question after completing DP 

class Solution {
public:
    bool isValid(int i, int balance, const string& s) {
        // If at any point balance < 0, toh invalid hoga 
        if (balance < 0) return false;

        // Base case: string khatam ho gaya 
        if (i == s.length()) return balance == 0;

        if (s[i] == '(') {
            return isValid(i + 1, balance + 1, s);
        } else if (s[i] == ')') {
            return isValid(i + 1, balance - 1, s);
        } else {
            // s[i] == '*'
            // Try as '(', as ')', and as empty
            return isValid(i + 1, balance + 1, s) ||  // '*' -> '('
                   isValid(i + 1, balance - 1, s) ||  // '*' -> ')'
                   isValid(i + 1, balance, s);        // '*' -> ''
        }
    }

    bool checkValidString(string s) {
        return isValid(0, 0, s);
    }
};
