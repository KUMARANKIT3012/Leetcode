// MEMOIZATION : 
class Solution {
public:
    int mod = 1e9 + 7;

    int f(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (ind == 0) {
            // If only one element:
            if (sum == 0 && arr[0] == 0) return 2; // {} and {0}
            if (sum == 0) return 1;                // only {}
            if (arr[0] == sum) return 1;           // {arr[0]}
            return 0;
        }

        if (dp[ind][sum] != -1) return dp[ind][sum];

        long long notTake = f(ind - 1, sum, arr, dp);
        long long take = 0;
        if (arr[ind] <= sum) take = f(ind - 1, sum - arr[ind], arr, dp);

        return dp[ind][sum] = (int)((notTake + take) % mod);
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, arr, dp);
    }
};




// TABULATION : 
class Solution {
public:
    int mod = 1e9 + 7;

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base for index 0
        if (arr[0] == 0) {
            dp[0][0] = 2;            // {} and {0}
        } else {
            dp[0][0] = 1;            // only {}
            if (arr[0] <= target) dp[0][arr[0]] = 1;
        }

        for (int ind = 1; ind < n; ++ind) {
            for (int sum = 0; sum <= target; ++sum) {
                int notTake = dp[ind - 1][sum];
                int take = 0;
                if (arr[ind] <= sum) take = dp[ind - 1][sum - arr[ind]];
                dp[ind][sum] = (notTake + take) % mod;
            }
        }

        return dp[n - 1][target];
    }
};




// SPACE OPTIMIZATION : 
class Solution {
public:
    int mod = 1e9 + 7;

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        // initialize for index 0
        if (arr[0] == 0) prev[0] = 2;   // {} and {0}
        else prev[0] = 1;              // {}

        if (arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;

        for (int ind = 1; ind < n; ++ind) {
            for (int sum = 0; sum <= target; ++sum) {
                long long notTake = prev[sum];
                long long take = 0;
                if (arr[ind] <= sum) take = prev[sum - arr[ind]];
                curr[sum] = (int)((notTake + take) % mod);
            }
            prev = curr;
            fill(curr.begin(), curr.end(), 0);
        }

        return prev[target];
    }
};
