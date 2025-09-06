// recursion 
class Solution {
private:
    int f(int i, int j, string &s, string &t) {
        if (j < 0) return 1;   // Matched all of t
        if (i < 0) return 0;   // s exhausted, t still remains

        if (s[i] == t[j]) {
            return f(i - 1, j - 1, s, t) + f(i - 1, j, s, t);
        } else {
            return f(i - 1, j, s, t);
        }
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        return f(n - 1, m - 1, s, t);
    }
};


// memoization - 
class Solution {
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (j < 0) return 1;   // All of t matched
        if (i < 0) return 0;   // s exhausted, t still remains

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        } else {
            return dp[i][j] = f(i - 1, j, s, t, dp);
        }
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};


// tabulation - 
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // Base case: Empty t can always be formed by any prefix of s
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};



// space optimized -
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<long long> prev(m + 1, 0);

        // Base case: Empty t can always be formed by any prefix of s
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            // Traverse backwards to avoid overwriting needed values
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    prev[j] = prev[j] + prev[j - 1];
                }
            }
        }
        return prev[m];
    }
};
