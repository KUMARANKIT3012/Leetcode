// MEMOIZATION (DP)
class Solution {
  public:
    int solve(int ind, vector<int>& height, vector<int>& dp) {
        if (ind == 0) return 0;  // base case: at first stone, no cost

        if (dp[ind] != -1) return dp[ind];  // already computed

        int left = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);

        int right = INT_MAX;
        if (ind > 1) {
            right = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
        }

        return dp[ind] = min(left, right);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(n - 1, height, dp);
    }
};


// TABULATION : 
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 0);

        dp[0] = 0;  // base case

        for (int i = 1; i < n; i++) {
            int fs = dp[i - 1] + abs(height[i] - height[i - 1]); // 1 step
            int ss = INT_MAX;

            if (i > 1) {
                ss = dp[i - 2] + abs(height[i] - height[i - 2]); // 2 steps
            }

            dp[i] = min(fs, ss);
        }

        return dp[n - 1]; // answer at last stone
    }
};



// SPACE OPTIMIZATION : 
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();

        int prev = 0;   // dp[i-1]
        int prev2 = 0;  // dp[i-2]

        for (int i = 1; i < n; i++) {
            int fs = prev + abs(height[i] - height[i - 1]); // one step
            int ss = INT_MAX;

            if (i > 1) {
                ss = prev2 + abs(height[i] - height[i - 2]); // two steps
            }

            int curi = min(fs, ss);

            // shift values forward
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};

