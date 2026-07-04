class Solution {
public:
    vector<int> days, costs;
    unordered_map<int, int> dp;
    int dfs(int i) {
        if (i >= days.size())
            return 0;
        if (dp.count(i))
            return dp[i];
        dp[i] = INT_MAX;
        vector<int> duration = {1, 7, 30};
        for (int k = 0; k < 3; k++) {
            int j = i;
            while (j < days.size() && days[j] < days[i] + duration[k])
                j++;
            dp[i] = min(dp[i], costs[k] + dfs(j));
        }
        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        return dfs(0);
    }
};
