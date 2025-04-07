class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int oddCount = 0;         // Number of odd numbers in the window
        int result = 0;           // Total number of nice subarrays
        int prefixEven = 0;       // Number of even numbers before the first odd in current window
        int n = nums.size();

        while (right < n) {
            // If current number is odd, increment oddCount
            if (nums[right] % 2 != 0) {
                oddCount++;
                prefixEven = 0;   // Reset prefixEven because we're starting a new valid window
            }

            // Shrink the window from the left to maintain exactly k odd numbers
            while (oddCount == k) {
                // Count even numbers before the first odd
                if (nums[left] % 2 == 0) {
                    prefixEven++;
                    left++;
                } else {
                    oddCount--;   // Exclude this odd from window
                    left++;
                    prefixEven++; // Include the odd also once
                }
            }

            // Add valid subarrays for the current window (with exactly k odds)
            result += prefixEven;
            right++;
        }

        return result;
    }
};
