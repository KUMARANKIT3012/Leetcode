class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            if(nums[i] > 0) break; // forgot this 
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; // here j and k will move or else woh infinite loop mein chala jaega 
                    k--; 
                    while(j < k && nums[j] == nums[j-1]) j++; // continue will not come here 
                    while(j < k && nums[k] == nums[k + 1]) k--; // this while loop will be inside the sum == k wala condition 
                    // ans it will be k+1 not k-1 in the above equation 
                }   
            }
        }
        return ans;
    }
};
