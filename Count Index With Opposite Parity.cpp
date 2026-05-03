class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int evenCount = 0, oddCount = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] % 2 == 0) {
                ans[i] = oddCount;
                evenCount++;
            } else {
                ans[i] = evenCount;
                oddCount++;
            }
        }

        return ans;
    }
};
