class Solution {
private:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (__int128)res * base % mod;
            base = (__int128)base * base % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int minNonZeroProduct(int p) {
        if (p == 1) return 1;
        
        long long mod = 1e9 + 7;
        long long max_val = (1ULL << p) - 1;
        long long target = max_val - 1;
        long long count = target / 2;
        
        long long val1 = power(target, count, mod);
        long long val2 = max_val % mod;
        
        return (val1 * val2) % mod;
    }
};
