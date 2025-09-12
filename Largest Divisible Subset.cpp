class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end()); // sorting main part hai 

        vector<int> dp(n, 1);        // LIS length ending at i
        vector<int> parent(n, -1);   // to reconstruct subset
        int maxLen = 1, lastIndex = 0;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct subset
        vector<int> result;
        while (lastIndex != -1) {
            result.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
