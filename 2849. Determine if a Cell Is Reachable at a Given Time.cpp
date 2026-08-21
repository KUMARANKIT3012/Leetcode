class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int s1 = abs(fx - sx);
        int s2 = abs(fy - sy);
        int maxi = max(s1, s2);
        if(maxi == 0 && t == 1) return false;
        if(maxi > t){
            return false;
        }

        return true;
    }
};
