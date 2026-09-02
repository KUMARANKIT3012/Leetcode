class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while(l <= r){
            int mid = (l + r)/2;
            long long tt = 0;
            for(int p : piles){
                tt += (p + mid - 1)/mid;
            }
            if(tt <= h){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
};
