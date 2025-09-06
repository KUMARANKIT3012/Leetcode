// memoization - 
class Solution {
private:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (i < 0) return j + 1;  // Need to insert remaining chars of s2
        if (j < 0) return i + 1;  // Need to delete remaining chars of s1

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
        }

        // Try insert, delete, replace
        int insertOp = f(i, j - 1, s1, s2, dp);
        int deleteOp = f(i - 1, j, s1, s2, dp);
        int replaceOp = f(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, word1, word2, dp);
    }
};




// tabulation - 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases
        for (int i = 0; i <= n; i++) dp[i][0] = i; // delete all
        for (int j = 0; j <= m; j++) dp[0][j] = j; // insert all

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j],     // delete
                                        dp[i][j - 1],     // insert
                                        dp[i - 1][j - 1]  // replace
                                       });
                }
            }
        }
        return dp[n][m];
    }
};




// space optimization - 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            cur[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = prev[j - 1];
                } else {
                    cur[j] = 1 + min({prev[j],     // delete
                                      cur[j - 1], // insert
                                      prev[j - 1] // replace
                                     });
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};
