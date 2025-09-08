// MEMOIZATION - 
class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind == prices.size()) return 0; // base case
        
        if (dp[ind][buy] != -1) return dp[ind][buy];
        
        int profit = 0;
        if (buy) {
            // Option 1: Buy
            profit = max(-prices[ind] + solve(ind + 1, 0, prices, dp),
                         0 + solve(ind + 1, 1, prices, dp));
        } else {
            // Option 2: Sell
            profit = max(prices[ind] + solve(ind + 1, 1, prices, dp),
                         0 + solve(ind + 1, 0, prices, dp));
        }
        
        return dp[ind][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};




// TABULATION - 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        // Base case: dp[n][0] = dp[n][1] = 0 (already filled with 0)
        
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0],
                                        0 + dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 1][1],
                                        0 + dp[ind + 1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};




// SPACE OPTIMIZATION - 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), cur(2, 0);
        
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    cur[buy] = max(-prices[ind] + ahead[0],
                                    0 + ahead[1]);
                } else {
                    cur[buy] = max(prices[ind] + ahead[1],
                                    0 + ahead[0]);
                }
            }
            ahead = cur;
        }
        
        return ahead[1];
    }
};
