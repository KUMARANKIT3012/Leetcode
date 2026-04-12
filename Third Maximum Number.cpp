class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int count = 1;
        for(int i = n-2; i>=0; i--){
            if(nums[i] != nums[i+1]){
                count++;
            }
            if(count == 3){
                return nums[i];
            }
        }
        return nums[n-1];
    }
};
