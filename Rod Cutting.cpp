// MEMOIZATION  - 
class Solution {
public:
    int solve(int idx, int N, vector<int>& price, vector<vector<int>>& dp) {
        // Base case: only first rod piece of length 1
        if (idx == 0) {
            return N * price[0]; 
        }

        if (dp[idx][N] != -1) return dp[idx][N];

        int notTake = solve(idx - 1, N, price, dp);
        int take = INT_MIN;
        int rodLength = idx + 1;
        if (rodLength <= N)
            take = price[idx] + solve(idx, N - rodLength, price, dp);

        return dp[idx][N] = max(take, notTake);
    }

    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n - 1, n, price, dp);
    }
};




// TABULATION - 
class Solution {
public:
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case: using only rod length 1
        for (int N = 0; N <= n; N++) {
            dp[0][N] = N * price[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int N = 0; N <= n; N++) {
                int notTake = dp[idx - 1][N];
                int take = INT_MIN;
                int rodLength = idx + 1;
                if (rodLength <= N)
                    take = price[idx] + dp[idx][N - rodLength];
                dp[idx][N] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};




// SPACE - OPTIMIZED - 
class Solution {
public:
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<int> dp(n + 1, 0);

        // Base case: using only rod length 1
        for (int N = 0; N <= n; N++) {
            dp[N] = N * price[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int N = 0; N <= n; N++) {
                int notTake = dp[N];
                int take = INT_MIN;
                int rodLength = idx + 1;
                if (rodLength <= N)
                    take = price[idx] + dp[N - rodLength];
                dp[N] = max(take, notTake);
            }
        }

        return dp[n];
    }
};
