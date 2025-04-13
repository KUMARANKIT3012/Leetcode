class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (freq[nums[right]] == 0) k--;  // new distinct number
            freq[nums[right]]++;

            while (k < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) k++; // lost a distinct number
                left++;
            }
            count += (right - left + 1);  // count subarrays ending at right
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1); // main logic yahi hai 
    }
};
