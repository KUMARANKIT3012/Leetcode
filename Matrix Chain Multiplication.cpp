// MEMOIZATION - 
class Solution {
  public:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        // base case: single matrix
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for(int k = i; k < j; k++) {
            int steps = arr[i-1] * arr[k] * arr[j] 
                        + solve(i, k, arr, dp) 
                        + solve(k+1, j, arr, dp);
            mini = min(mini, steps);
        }
        
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, n-1, arr, dp);
    }
};




// TABULATION - 
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // dp[i][j] = min cost of multiplying matrices from i to j
        
        for(int len = 2; len < n; len++) { // length of chain
            for(int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = 1e9;
                for(int k = i; k < j; k++) {
                    int steps = arr[i-1] * arr[k] * arr[j] 
                              + dp[i][k] 
                              + dp[k+1][j];
                    dp[i][j] = min(dp[i][j], steps);
                }
            }
        }
        
        return dp[1][n-1];
    }
};
