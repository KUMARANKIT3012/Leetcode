
// MEMOIZATION - 
class Solution {
public:
    int solve(int i, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if(i == 0) {
            if(target % coins[0] == 0) return target / coins[0];
            return 1e9; // impossible
        }
        if(dp[i][target] != -1) return dp[i][target];

        int notTake = solve(i-1, target, coins, dp);
        int take = 1e9;
        if(coins[i] <= target) {
            take = 1 + solve(i, target - coins[i], coins, dp);
        }
        return dp[i][target] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, amount, coins, dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};




// TABULATION - 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));

        // Base case: using only the first coin
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) dp[0][t] = t / coins[0];
        }

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= amount; t++) {
                int notTake = dp[i-1][t];
                int take = 1e9;
                if(coins[i] <= t) {
                    take = 1 + dp[i][t - coins[i]];
                }
                dp[i][t] = min(take, notTake);
            }
        }

        int ans = dp[n-1][amount];
        return (ans >= 1e9 ? -1 : ans);
    }
};





// SPACE-OPTIMIZED - 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 1e9), curr(amount+1, 1e9);

        // Base case
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) prev[t] = t / coins[0];
        }

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= amount; t++) {
                int notTake = prev[t];
                int take = 1e9;
                if(coins[i] <= t) {
                    take = 1 + curr[t - coins[i]];
                }
                curr[t] = min(take, notTake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        return (ans >= 1e9 ? -1 : ans);
    }
};
