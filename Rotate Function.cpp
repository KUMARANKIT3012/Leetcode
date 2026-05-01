class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0;
        long f = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            f += i * nums[i];
        }
        
        long ans = f;
        
        for(int k = 1; k < n; k++){
            f = f + sum - (long)n * nums[n - k];
            ans = max(ans, f);
        }
        
        return ans;
    }
};
