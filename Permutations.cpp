class Solution {
public:
    void getperms(vector<int>&nums, int idx, vector<vector<int>>&ans){
        if(idx == nums.size()){ // base case 
            ans.push_back({nums});
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            // main logic
            swap(nums[idx], nums[i]);
            getperms(nums, idx+1, ans);
            // backtracking
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int idx= nums[0];
        vector<vector<int>> ans;
        getperms(nums, 0, ans);
        return ans;
    }
};
