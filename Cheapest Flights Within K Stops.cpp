class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        vector<int> prices(n, INF);
        prices[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> tmpPrices = prices;
            for (auto& flight : flights) {
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];
                if (prices[s] == INF)
                    continue;
                if (prices[s] + p < tmpPrices[d]) tmpPrices[d] = prices[s] + p;
            }
            prices = tmpPrices;
        }
        return prices[dst] == INF ? -1 : prices[dst];
    }
};
