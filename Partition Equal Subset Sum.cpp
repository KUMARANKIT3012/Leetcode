// MEMOIZATION : 
class Solution {
public:
    bool subsetSum(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true; // found subset
        if (idx == 0) return nums[0] == target; // only one element

        if (dp[idx][target] != -1) return dp[idx][target];

        bool notTake = subsetSum(idx - 1, target, nums, dp);
        bool take = false;
        if (nums[idx] <= target) {
            take = subsetSum(idx - 1, target - nums[idx], nums, dp);
        }
        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false; // odd sum can't be split equally

        int target = total / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return subsetSum(n - 1, target, nums, dp);
    }
};




// TABULATION  :
 class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base cases
        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[i - 1][t];
                bool take = false;
                if (nums[i] <= t) take = dp[i - 1][t - nums[i]];
                dp[i][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};



// SPACE-OPTIMIZATION : 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> prev(target + 1, false), curr(target + 1, false);

        prev[0] = curr[0] = true;
        if (nums[0] <= target) prev[nums[0]] = true;

        for (int i = 1; i < nums.size(); i++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = prev[t];
                bool take = false;
                if (nums[i] <= t) take = prev[t - nums[i]];
                curr[t] = take || notTake;
            }
            prev = curr;
        }

        return prev[target];
    }
};
