class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;
        while(st < end){
            int mid = st + (end - st)/2;
            if(nums[mid] > nums[end]){
                st = mid + 1;
            }
            else if(nums[mid] < nums[end]){
                end = mid;
            }
            else{
                end = mid-1;
            }
        }
        return nums[st];
    }
};
