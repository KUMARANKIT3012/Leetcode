// MEMOIZATION - 
class Solution {
public:
    int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) {
            return (target % coins[0] == 0); // only one type of coin left
        }
        if (dp[ind][target] != -1) return dp[ind][target];

        int notTake = f(ind - 1, target, coins, dp);
        int take = 0;
        if (coins[ind] <= target) 
            take = f(ind, target - coins[ind], coins, dp);

        return dp[ind][target] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};



// TABULATION - 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case: using only coins[0]
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) dp[0][t] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                int notTake = dp[ind-1][target];
                int take = 0;
                if (coins[ind] <= target) take = dp[ind][target - coins[ind]];
                dp[ind][target] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};





// SPACE OPTIMIZED - 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);

        // Base case
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) prev[t] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                int notTake = prev[target];
                int take = 0;
                if (coins[ind] <= target) take = cur[target - coins[ind]];
                cur[target] = take + notTake;
            }
            prev = cur;
        }
        return prev[amount];
    }
};

