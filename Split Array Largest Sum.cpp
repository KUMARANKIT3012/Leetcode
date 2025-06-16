class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int maxSum) {
        int splits = 1;
        int currSum = 0;

        for (int num : nums) {
            if (currSum + num > maxSum) {
                splits++;
                currSum = num;
                if (splits > k) return false;
            } else {
                currSum += num;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;  // Try for smaller max
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
