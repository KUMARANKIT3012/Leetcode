// MEMOIZATION (DP) : 
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        // Out of bounds or obstacle
        if (i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;

        // Reached destination
        if (i == m-1 && j == n-1) return 1;

        // Already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Move right + down
        int right = solve(i, j+1, obstacleGrid, dp);
        int down  = solve(i+1, j, obstacleGrid, dp);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, obstacleGrid, dp);
    }
};



// TABULATION : 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Start cell
        if (obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;  // obstacle
                } else {
                    if (i > 0) dp[i][j] += dp[i-1][j];
                    if (j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};



// SPACE OPTIMIZATION : 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;  // obstacle
                } else if (i == 0 && j == 0) {
                    curr[j] = 1;  // start
                } else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j-1] : 0;
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
