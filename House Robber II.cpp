class Solution {
public:
    // helper function: normal house robber on a linear array
    int robLinear(vector<int>& nums, int start, int end) {
        int prev = 0, prev2 = 0;

        for (int i = start; i <= end; i++) {
            int take = nums[i] + (i > start ? prev2 : 0);
            int notTake = prev;
            int curi = max(take, notTake);

            prev2 = prev;
            prev = curi;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0]; // only one house

        // Case 1: exclude last house
        int case1 = robLinear(nums, 0, n - 2);

        // Case 2: exclude first house
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};
