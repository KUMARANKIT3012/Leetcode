// MEMOIZATION - 
class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            int cost = cuts[j+1] - cuts[i-1] 
                     + f(i, ind-1, cuts, dp) 
                     + f(ind+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c+2, vector<int>(c+2, -1));
        return f(1, c, cuts, dp);
    }
};



// TABULATION - 
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

        // len = length of subarray (number of cuts being considered)
        for (int len = 1; len <= c; len++) {
            for (int i = 1; i <= c - len + 1; i++) {
                int j = i + len - 1;
                int mini = INT_MAX;
                for (int ind = i; ind <= j; ind++) {
                    int cost = cuts[j+1] - cuts[i-1] 
                             + dp[i][ind-1] 
                             + dp[ind+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};
