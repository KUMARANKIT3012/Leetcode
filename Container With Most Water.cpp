class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxarea = 0;
        int lh = 0;
        int rh = n-1;
        while(lh <= rh){
            int ht = min(height[lh], height[rh]);
            int wt = rh - lh;
            int area = ht * wt;
            maxarea = max(area, maxarea);
            if(height[lh] < height[rh]){
                lh++;
            }
            else{
                rh--;
            }
        }
        return maxarea;
    }
};
