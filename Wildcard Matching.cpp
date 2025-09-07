// RECURANCE - 
class Solution {
public:
    bool solve(int i, int j, string &pattern, string &text) {
        // Base cases
        if (i < 0 && j < 0) return true;   // both finished
        if (i < 0 && j >= 0) return false; // pattern finished, text not
        if (j < 0 && i >= 0) {
            for (int ii = 0; ii <= i; ii++) {
                if (pattern[ii] != '*') return false;
            }
            return true;
        }

        // If chars match or '?'
        if (pattern[i] == text[j] || pattern[i] == '?') {
            return solve(i-1, j-1, pattern, text);
        }

        // If '*'
        if (pattern[i] == '*') {
            return solve(i-1, j, pattern, text) || solve(i, j-1, pattern, text);
        }

        return false;
    }

    bool isMatch(string text, string pattern) {
        return solve(pattern.size()-1, text.size()-1, pattern, text);
    }
};




// MEMOIZATION - 
class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string &pattern, string &text) {
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        if (j < 0 && i >= 0) {
            for (int ii = 0; ii <= i; ii++) {
                if (pattern[ii] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (pattern[i] == text[j] || pattern[i] == '?') {
            return dp[i][j] = solve(i-1, j-1, pattern, text);
        }

        if (pattern[i] == '*') {
            return dp[i][j] = (solve(i-1, j, pattern, text) || solve(i, j-1, pattern, text));
        }

        return dp[i][j] = false;
    }

    bool isMatch(string text, string pattern) {
        dp.assign(pattern.size(), vector<int>(text.size(), -1));
        return solve(pattern.size()-1, text.size()-1, pattern, text);
    }
};




// TABULATION - 
class Solution {
public:
    bool isMatch(string text, string pattern) {
        int n = pattern.size(), m = text.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;

        // Pattern prefixes with only '*' can match empty text
        for (int i = 1; i <= n; i++) {
            bool allStars = true;
            for (int k = 1; k <= i; k++) {
                if (pattern[k-1] != '*') {
                    allStars = false;
                    break;
                }
            }
            dp[i][0] = allStars;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pattern[i-1] == text[j-1] || pattern[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (pattern[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
