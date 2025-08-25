// MEMOIZATION - 
class Solution {
public:
    bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;          // sum found
        if (ind == 0) return (arr[0] == target); // only first element check

        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTake = f(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
            take = f(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = (take || notTake);
    }

    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(n - 1, k, arr, dp);
    }
};



// TABULATION : 
class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // Base case
        for (int i = 0; i < n; i++) dp[i][0] = true; // target=0 is always possible
        if (arr[0] <= k) dp[0][arr[0]] = true;

        // Fill dp
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = take || notTake;
            }
        }

        return dp[n - 1][k];
    }
};




// SPACE OPTIMIZATION : 
class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<bool> prev(k + 1, false), curr(k + 1, false);

        prev[0] = true;
        if (arr[0] <= k) prev[arr[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            curr[0] = true;
            for (int target = 1; target <= k; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (arr[ind] <= target)
                    take = prev[target - arr[ind]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }

        return prev[k];
    }
};
