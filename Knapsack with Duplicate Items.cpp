// MEMOIZATION - 
class Solution {
public:
    int solve(int idx, int capacity, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
        if (idx == 0) {
            return (capacity / wt[0]) * val[0]; // can take multiple copies
        }
        
        if (dp[idx][capacity] != -1) return dp[idx][capacity];
        
        int notTake = solve(idx - 1, capacity, wt, val, dp);
        int take = INT_MIN;
        if (wt[idx] <= capacity)
            take = val[idx] + solve(idx, capacity - wt[idx], wt, val, dp); // notice `idx` stays same (unbounded)
        
        return dp[idx][capacity] = max(take, notTake);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return solve(n - 1, capacity, wt, val, dp);
    }
};




// TABULATION - 
class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // Base case
        for (int W = 0; W <= capacity; W++) {
            dp[0][W] = (W / wt[0]) * val[0]; // multiple copies allowed
        }

        for (int i = 1; i < n; i++) {
            for (int W = 0; W <= capacity; W++) {
                int notTake = dp[i - 1][W];
                int take = INT_MIN;
                if (wt[i] <= W)
                    take = val[i] + dp[i][W - wt[i]]; // stay at same row
                dp[i][W] = max(take, notTake);
            }
        }

        return dp[n - 1][capacity];
    }
};
