// MEMOIZATION - 
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if (ind == prices.size()) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if (buy) {
            // Option 1: Buy stock
            int take = -prices[ind] + f(ind + 1, 0, prices, fee, dp);
            // Option 2: Skip
            int notTake = f(ind + 1, 1, prices, fee, dp);
            profit = max(take, notTake);
        } else {
            // Option 1: Sell stock (pay fee)
            int sell = prices[ind] - fee + f(ind + 1, 1, prices, fee, dp);
            // Option 2: Skip
            int notSell = f(ind + 1, 0, prices, fee, dp);
            profit = max(sell, notSell);
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, fee, dp);
    }
};




// TABULATION - 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int take = -prices[ind] + dp[ind + 1][0];
                    int notTake = dp[ind + 1][1];
                    profit = max(take, notTake);
                } else {
                    int sell = prices[ind] - fee + dp[ind + 1][1];
                    int notSell = dp[ind + 1][0];
                    profit = max(sell, notSell);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
};




// SPACE OPTIMIZED - 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            curr[1] = max(-prices[ind] + ahead[0], ahead[1]);
            curr[0] = max(prices[ind] - fee + ahead[1], ahead[0]);
            ahead = curr;
        }

        return ahead[1];
    }
};
