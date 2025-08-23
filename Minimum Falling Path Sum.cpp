// MEMOIZATION (DP) : 
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        if (j < 0 || j >= n) return 1e9;  // out of bounds
        if (i == n - 1) return matrix[i][j]; // last row

        if (dp[i][j] != -1) return dp[i][j];

        int down = matrix[i][j] + f(i + 1, j, matrix, dp);
        int leftDiag = matrix[i][j] + f(i + 1, j - 1, matrix, dp);
        int rightDiag = matrix[i][j] + f(i + 1, j + 1, matrix, dp);

        return dp[i][j] = min({down, leftDiag, rightDiag});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mini = 1e9;

        for (int j = 0; j < n; j++) {
            mini = min(mini, f(0, j, matrix, dp));
        }

        return mini;
    }
};



// TABULATION  : 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // base case: last row = matrix’s last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        // bottom-up filling
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = matrix[i][j] + dp[i + 1][j];
                int leftDiag = matrix[i][j] + (j > 0 ? dp[i + 1][j - 1] : 1e9);
                int rightDiag = matrix[i][j] + (j < n - 1 ? dp[i + 1][j + 1] : 1e9);

                dp[i][j] = min({down, leftDiag, rightDiag});
            }
        }

        // answer = min of top row
        int mini = 1e9;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[0][j]);
        }
        return mini;
    }
};



// SPACE-OPTIMIZATION : 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> front(n, 0), cur(n, 0);

        // base case: last row
        for (int j = 0; j < n; j++) {
            front[j] = matrix[n - 1][j];
        }

        // bottom-up
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = matrix[i][j] + front[j];
                int leftDiag = matrix[i][j] + (j > 0 ? front[j - 1] : 1e9);
                int rightDiag = matrix[i][j] + (j < n - 1 ? front[j + 1] : 1e9);

                cur[j] = min({down, leftDiag, rightDiag});
            }
            front = cur;
        }

        // answer = min of top row
        int mini = 1e9;
        for (int j = 0; j < n; j++) {
            mini = min(mini, front[j]);
        }
        return mini;
    }
};
