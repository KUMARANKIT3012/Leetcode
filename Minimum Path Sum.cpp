// MEMOIZATION (DP) : 
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size(), n = grid[0].size();

        // Out of bounds
        if (i < 0 || j < 0) return 1e9; // large number

        // Base case: start point
        if (i == 0 && j == 0) return grid[0][0];

        // Already computed
        if (dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + solve(i-1, j, grid, dp);
        int left = grid[i][j] + solve(i, j-1, grid, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};


// TABULATION : 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int up = (i > 0) ? dp[i-1][j] : 1e9;
                int left = (j > 0) ? dp[i][j-1] : 1e9;

                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
        return dp[m-1][n-1];
    }
};



// SPACE_OPTIMIZATION : 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                } else {
                    int up = (i > 0) ? prev[j] : 1e9;
                    int left = (j > 0) ? curr[j-1] : 1e9;
                    curr[j] = grid[i][j] + min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

