class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        for(int i =0 ; i<nums.size(); i++){
            count += nums[i];
            maxi = max(maxi, count);
            if(nums[i] == 0){ // the logic is preety similar to kadane's algorithm:
                count = 0;
            }
        }
        return maxi;
    }
};
