class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;//answer
        int lp=0;
        int rp=height.size()-1;
        while(lp<rp){
            int width=rp-lp;
            int ht=min(height[lp],height[rp]);
            int currwater=width*ht;
            maxwater=max(maxwater,currwater);
            
            height[lp]<height[rp]?lp++:rp--;
        }
        return maxwater;
    }
};
