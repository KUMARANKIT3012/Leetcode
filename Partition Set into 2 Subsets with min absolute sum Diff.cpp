// MEMOIZATION : 
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for (int x : nums) totSum += x;

        vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= totSum) dp[0][nums[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= totSum; target++) {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (nums[ind] <= target) take = dp[ind - 1][target - nums[ind]];
                dp[ind][target] = take || notTake;
            }
        }

        int mini = 1e9;
        for (int s1 = 0; s1 <= totSum / 2; s1++) {
            if (dp[n - 1][s1]) {
                int s2 = totSum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }
        return mini;
    }
};




// TABULATION : 
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for (int x : nums) totSum += x;

        vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= totSum) dp[0][nums[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= totSum; target++) {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (nums[ind] <= target) take = dp[ind - 1][target - nums[ind]];
                dp[ind][target] = take || notTake;
            }
        }

        int mini = 1e9;
        for (int s1 = 0; s1 <= totSum / 2; s1++) {
            if (dp[n - 1][s1]) {
                int s2 = totSum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }
        return mini;
    }
};




// SPACE OPTIMIZED : 
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for (int x : nums) totSum += x;

        vector<bool> prev(totSum + 1, false), cur(totSum + 1, false);
        prev[0] = true;
        if (nums[0] <= totSum) prev[nums[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            cur[0] = true;
            for (int target = 1; target <= totSum; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (nums[ind] <= target) take = prev[target - nums[ind]];
                cur[target] = take || notTake;
            }
            prev = cur;
        }

        int mini = 1e9;
        for (int s1 = 0; s1 <= totSum / 2; s1++) {
            if (prev[s1]) {
                int s2 = totSum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }
        return mini;
    }
};

