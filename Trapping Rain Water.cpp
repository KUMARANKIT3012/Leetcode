class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;  // Edge case: empty array
        
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0, total = 0;
        
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < lmax) {
                    total += lmax - height[l];
                } else {
                    lmax = height[l];
                }
                l++;
            } else {
                if (height[r] < rmax) {
                    total += rmax - height[r];
                } else {
                    rmax = height[r];
                }
                r--;
            }
        }
        
        return total;
    }
};
