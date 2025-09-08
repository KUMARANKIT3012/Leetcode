// MEMOIZATION - 
class Solution {
public:
    int solve(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (ind == prices.size() || cap == 0) return 0; // No days left or no transactions left
        
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        int profit = 0;
        if (buy) {
            // Option 1: Buy stock
            profit = max(-prices[ind] + solve(ind+1, 0, cap, prices, dp),
                          0 + solve(ind+1, 1, cap, prices, dp)); // Skip
        } else {
            // Option 2: Sell stock
            profit = max(prices[ind] + solve(ind+1, 1, cap-1, prices, dp),
                          0 + solve(ind+1, 0, cap, prices, dp)); // Skip
        }
        
        return dp[ind][buy][cap] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2; // Example: at most 2 transactions
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap+1, -1)));
        return solve(0, 1, cap, prices, dp);
    }
};



// TABULATION - 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2; // At most 2 transactions
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(cap+1, 0)));
        
        // Base case: dp[n][buy][cap] = 0 and dp[ind][buy][0] = 0 already initialized
        
        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int c = 1; c <= cap; c++) {
                    if (buy) {
                        dp[ind][buy][c] = max(-prices[ind] + dp[ind+1][0][c],
                                               0 + dp[ind+1][1][c]);
                    } else {
                        dp[ind][buy][c] = max(prices[ind] + dp[ind+1][1][c-1],
                                               0 + dp[ind+1][0][c]);
                    }
                }
            }
        }
        
        return dp[0][1][cap];
    }
};




// SPACE OPTIMIZED - 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2; // At most 2 transactions
        
        vector<vector<int>> ahead(2, vector<int>(cap+1, 0)), cur(2, vector<int>(cap+1, 0));
        
        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int c = 1; c <= cap; c++) {
                    if (buy) {
                        cur[buy][c] = max(-prices[ind] + ahead[0][c],
                                           0 + ahead[1][c]);
                    } else {
                        cur[buy][c] = max(prices[ind] + ahead[1][c-1],
                                           0 + ahead[0][c]);
                    }
                }
            }
            ahead = cur;
        }
        
        return ahead[1][cap];
    }
};
