class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        long long a = nums[0];
        long long b = nums[1];
        long long c = nums[n - 2];
        long long d = nums[n - 1];
        
        const long long x = 100000;
        
        return max({a * b * x, c * d * x, a * d * -x});
    }
};
