class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0;
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex]) minIndex = i;
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        int count1 = right + 1;          
        int count2 = n - left;           
        int count3 = left + 1 + n - right; 

        return min({count1, count2, count3});
    }
};
