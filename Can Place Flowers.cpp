class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        int countz = 0;
        for(int i = 0; i < s; i++){            
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == s-1 || flowerbed[i+1] == 0)){
                countz++;
                flowerbed[i] = 1;
            }
        }
        if(countz >= n) return true;
        else return false;
    }
};
