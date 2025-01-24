class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // sort the array
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]){  // first condition check
                continue;
            }
            int j=i+1, k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++; k--;
                    while(j<k && nums[j] == nums[j-1]){ // second condition check
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};
