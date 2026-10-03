class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i += 3) {
            if(i + 2 >= n || nums[i] != nums[i + 2]){
                return nums[i];
            }
        }
        return -1;
    }
};
