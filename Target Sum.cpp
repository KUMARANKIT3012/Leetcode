class Solution {
public:
    int findWays(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<int> prev(tar+1, 0), cur(tar+1, 0);

        // base case
        if (arr[0] == 0) prev[0] = 2; // pick or not pick 0
        else prev[0] = 1;

        if (arr[0] != 0 && arr[0] <= tar) prev[arr[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int sum = 0; sum <= tar; sum++) {
                int notTake = prev[sum];
                int take = 0;
                if (arr[ind] <= sum) take = prev[sum - arr[ind]];
                cur[sum] = (notTake + take);
            }
            prev = cur;
        }
        return prev[tar];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = 0;
        for (auto &x : nums) totSum += x;

        // invalid cases
        if (totSum < abs(target) || (totSum + target) % 2 != 0) return 0;

        int S1 = (totSum + target) / 2;
        return findWays(nums, S1);
    }
};
