class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<long long> profit(k + 1, 0);
        vector<long long> buy(k + 1, LLONG_MIN);
        vector<long long> sell(k + 1, LLONG_MIN);

        for (int price : prices) {
            vector<long long> newProfit = profit;
            vector<long long> newBuy = buy;
            vector<long long> newSell = sell;

            for (int i = 0; i < k; i++) {
                newBuy[i] = max(newBuy[i], profit[i] - price);
                newSell[i] = max(newSell[i], profit[i] + price);

                if (buy[i] != LLONG_MIN)
                    newProfit[i + 1] = max(newProfit[i + 1], buy[i] + price);

                if (sell[i] != LLONG_MIN)
                    newProfit[i + 1] = max(newProfit[i + 1], sell[i] - price);
            }

            profit = newProfit;
            buy = newBuy;
            sell = newSell;
        }

        return *max_element(profit.begin(), profit.end());
    }
};
