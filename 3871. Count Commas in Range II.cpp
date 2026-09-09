class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        
        if (n >= 1000)
            ans += n - 999;
        
        if (n >= 1000000)
            ans += n - 999999;
        
        if (n >= 1000000000)
            ans += n - 999999999;
        
        if (n >= 1000000000000LL)
            ans += n - 999999999999LL;
        
        if (n >= 1000000000000000LL)
            ans += n - 999999999999999LL;
        
        return ans;
    }
};
