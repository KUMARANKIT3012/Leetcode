// MEMOIZATION (DP) : 
class Solution {
  public:
    int solve(int ind, vector<int>& arr, vector<int>& dp) {
        if (ind == 0) return arr[0];   // base case
        if (ind < 0) return 0;         // invalid index

        if (dp[ind] != -1) return dp[ind];  // already computed

        // Option 1: Pick current element
        int pick = arr[ind] + solve(ind - 2, arr, dp);

        // Option 2: Do not pick current element
        int notPick = 0 + solve(ind - 1, arr, dp);

        return dp[ind] = max(pick, notPick);
    }

    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(n - 1, arr, dp);
    }
};



// TABULATION WITH SPACE OPTIMIZATION : 
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int prev = arr[0];   // dp[i-1]
        int prev2 = 0;       // dp[i-2]

        for (int i = 1; i < n; i++) {
            int take = arr[i];
            if (i > 1) take += prev2;

            int notTake = 0 + prev;

            int curi = max(take, notTake);

            // shift for next iteration
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};
