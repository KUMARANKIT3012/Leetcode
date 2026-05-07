class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<long long, long long> right, left;
        for(int x : nums) {
            right[x]++;
        }

        long long ans = 0;
        for(int j = 0; j < n; j++) {
            right[nums[j]]--;
            long long target = 1LL * nums[j] * 2;
            long long leftCount = left[target];
            long long rightCount = right[target];
            ans = (ans + (leftCount * rightCount) % MOD) % MOD;
            left[nums[j]]++;
        }

        return ans;
    }
};
