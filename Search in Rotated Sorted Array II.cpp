class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int st = 0;
        int end = nums.size()-1;
        while(st<=end){
            int mid = st + (end - st)/2;
            if(nums[mid] == tar) return true;
            if(nums[st] == nums[mid] && nums[mid] == nums[end]){
                st++;
                end--;
            }
            else if(nums[st] <= nums[mid]){
                if(nums[st] <= tar && tar <= nums[mid]){
                    end = mid-1;
                }
                else{
                    st = mid+1;
                }
            }
            else{
                if(nums[mid] <= tar && tar <= nums[end]){
                    st = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return false;
    }
};
