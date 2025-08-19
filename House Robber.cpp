class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev = nums[0];  // dp[i-1]
        int prev2 = 0;       // dp[i-2]

        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1) take += prev2;

            int notTake = 0 + prev;

            int curi = max(take, notTake);

            // move forward
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};
