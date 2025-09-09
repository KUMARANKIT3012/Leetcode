// MEMOIZATION - 
class Solution {
public:
    int dp[1001][2][101]; // [index][buy][cap]

    int f(int ind, int buy, int cap, vector<int>& prices, int n) {
        if (ind == n || cap == 0) return 0;
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit = 0;
        if (buy) {
            // Either buy or skip
            profit = max(-prices[ind] + f(ind + 1, 0, cap, prices, n),
                         0 + f(ind + 1, 1, cap, prices, n));
        } else {
            // Either sell or skip
            profit = max(prices[ind] + f(ind + 1, 1, cap - 1, prices, n),
                         0 + f(ind + 1, 0, cap, prices, n));
        }

        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return f(0, 1, k, prices, n);
    }
};



// TABULATION - 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<vector<int>>> dp(n + 1,
            vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy) {
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap],
                                                 0 + dp[ind + 1][1][cap]);
                    } else {
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1],
                                                 0 + dp[ind + 1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};




// SPACE OPTIMIZED - 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy) {
                        cur[buy][cap] = max(-prices[ind] + ahead[0][cap], 0 + ahead[1][cap]);
                    } else {
                        cur[buy][cap] = max(prices[ind] + ahead[1][cap - 1], 0 + ahead[0][cap]);
                    }
                }
            }
            ahead = cur;
        }

        return ahead[1][k];
    }
};

