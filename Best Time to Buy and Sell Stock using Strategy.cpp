class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half = k / 2;

        long long baseProfit = 0;

        for (int i = 0; i < n; i++) {
            baseProfit += 1LL * prices[i] * strategy[i];
        }

        long long extra = 0;

        for (int i = 0; i < k; i++) {
            long long oldVal = 1LL * prices[i] * strategy[i];
            long long newVal = (i < half ? 0LL : 1LL * prices[i]);

            extra += newVal - oldVal;
        }

        long long best = max(0LL, extra);

        for (int l = 1; l + k - 1 < n; l++) {
            int removeIdx = l - 1;
            int middleIdx = l + half - 1;
            int addIdx = l + k - 1;

            extra -= (0LL - 1LL * prices[removeIdx] * strategy[removeIdx]);

            extra -= (1LL * prices[middleIdx] -
                      1LL * prices[middleIdx] * strategy[middleIdx]);

            extra += (0LL -
                      1LL * prices[middleIdx] * strategy[middleIdx]);

            extra += (1LL * prices[addIdx] -
                      1LL * prices[addIdx] * strategy[addIdx]);

            best = max(best, extra);
        }

        return baseProfit + best;
    }
};
