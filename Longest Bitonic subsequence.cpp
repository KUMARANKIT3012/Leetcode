class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        if(n == 0) return 0;
        vector<int> dp1(n, 1), dp2(n, 1);

        // LIS ending at i
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && dp1[j] + 1 > dp1[i])
                    dp1[i] = dp1[j] + 1;
            }
        }

        // LIS (i.e. LDS) starting at i (from right)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] < nums[i] && dp2[j] + 1 > dp2[i])
                    dp2[i] = dp2[j] + 1;
            }
        }

        int maxi = 0;
        // Only consider peaks that have both increasing and decreasing parts
        for (int i = 0; i < n; ++i) {
            if (dp1[i] > 1 && dp2[i] > 1)
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }

        return maxi;
    }
};
