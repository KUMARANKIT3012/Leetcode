// isme I'll use if currsum < 0 not arr[i] == 0

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            currsum+=nums[i];
            maxsum=max(currsum,maxsum);
            if(currsum<0){
                currsum=0;
            }
        }
        return maxsum;
    }
};
