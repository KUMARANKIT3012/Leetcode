class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0], fast=nums[0];
        // 1st part of the code:
        do{
            slow=nums[slow]; // +1
            fast=nums[nums[fast]]; // +2
        }
        while(slow != fast);

        //2nd part of the code
        slow=nums[0];
        while(slow != fast){
            slow=nums[slow]; // +1
            fast=nums[fast]; // +1
        }
        return slow;
    }
};




// second method : 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i =1; i<n; i++){
            if(nums[i] == nums[i-1]){
                return nums[i];
            }
        }
        return -1;
    }
};
