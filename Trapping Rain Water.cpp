class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int st = 0;
        int end = n-1;
        int total = 0;
        int lmax = 0;
        int rmax = 0;
        while(st < end){
            if(height[st] < height[end]){
                if(height[st] < lmax){
                    total += lmax - height[st];
                }
                else{
                    lmax = height[st];
                }
                st++;
            }
            else{
                if(height[end] < rmax){
                    total += rmax - height[end];
                }
                else{
                    rmax = height[end];
                }
                end--;
            }
        }
        return total;
    }
};
