class Solution {
public:
    long long coloredCells(int n) {
        long long  sum = 1;
        if(n == 1) return 1;
        long long diff = 4;
        for(long long i = 2; i<=n; i++){
            sum += diff;
            diff += 4;
        }

        return sum;
    }
};
