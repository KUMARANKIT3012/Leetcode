class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for (long long x = 1000; x <= n; x *= 1000) {
            ans += n - x + 1;
            if (x > n / 1000) break;
        }
        return ans;
    }
};
