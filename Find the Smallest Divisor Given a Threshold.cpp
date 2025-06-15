class Solution {
public:
    // Helper to calculate sum of ceil(nums[i]/div) for all elements
    int sumofdiv(vector<int>& nums, int div) {
        int sum = 0;
        for (int num : nums) {
            sum += ceil((double)num / (double)div);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sumofdiv(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1; // mil bhi gaya to look for smaller elt 
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
