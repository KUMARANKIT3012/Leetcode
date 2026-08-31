class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        // int maxi = INT_MIN;
        // int curr = nums[0];
        for(int i = 1; i<nums.size()-1; i++){
            if(nums[i] + nums[i+1] > nums[i-1]){
                return nums[i] + nums[i+1] + nums[i-1];
            }   
        }
        return 0;
    }
};
