// MEMOIZATION (DP) : 
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();
        if (i == n - 1) return triangle[i][j]; // base case: last row
        
        if (dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + f(i + 1, j, triangle, dp);
        int diag = triangle[i][j] + f(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, triangle, dp);
    }
};



// TABULATION : 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // base case: last row = triangle’s last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // bottom-up calculation
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diag);
            }
        }

        return dp[0][0]; // answer at top
    }
};


// SPACE-OPTIMIZATION : 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0), cur(n, 0);

        // base case: last row
        for (int j = 0; j < n; j++) {
            front[j] = triangle[n - 1][j];
        }

        // bottom-up
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j + 1];
                cur[j] = min(down, diag);
            }
            front = cur; // update
        }

        return front[0];
    }
};
