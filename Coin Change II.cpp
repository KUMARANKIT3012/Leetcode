class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int numCoins = coins.size();
        int targetAmount = amount;
        unsigned dp[numCoins + 1][targetAmount + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int i = 1; i <= numCoins; ++i) {
            for (int j = 0; j <= targetAmount; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[numCoins][targetAmount];
    }
};
