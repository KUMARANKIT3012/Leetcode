// MEMOIZATION - 
class Solution {
public:
    int dp[5001][2]; // [index][buy]

    int f(int ind, int buy, vector<int>& prices, int n) {
        if (ind >= n) return 0; // can't trade beyond end
        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + f(ind + 1, 0, prices, n),  // Buy
                         0 + f(ind + 1, 1, prices, n));            // Skip
        } else {
            profit = max(prices[ind] + f(ind + 2, 1, prices, n),   // Sell + cooldown
                         0 + f(ind + 1, 0, prices, n));            // Skip
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return f(0, 1, prices, n);
    }
};




// TABULATION - 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0)); 
        // n+2 to avoid out-of-bound when ind+2

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0],
                                       0 + dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 2][1],
                                       0 + dp[ind + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};




// SPACE OPTIMIZED - 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead1(2, 0), ahead2(2, 0), cur(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    cur[buy] = max(-prices[ind] + ahead1[0],
                                   0 + ahead1[1]);
                } else {
                    cur[buy] = max(prices[ind] + ahead2[1],
                                   0 + ahead1[0]);
                }
            }
            ahead2 = ahead1;
            ahead1 = cur;
        }

        return ahead1[1];
    }
};
