class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int primary = nums[i][i];
            int secondary = nums[i][n - i - 1];
            if (isPrime(primary)) {
                maxi = max(maxi, primary);
            }
            if (isPrime(secondary)) {
                maxi = max(maxi, secondary);
            }
        }
        return maxi;
    }
};
