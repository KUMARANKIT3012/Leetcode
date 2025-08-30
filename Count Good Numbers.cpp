class Solution {
public:
    const long long MOD = 1e9+7;
    
    // Recursive fast power
    long long power(long long base, long long exp) {
        if (exp == 0) return 1;
        
        long long half = power(base, exp / 2);
        half = (half * half) % MOD;
        
        if (exp % 2) return (half * base) % MOD;
        return half;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // ceil(n/2)
        long long oddCount = n / 2;         // floor(n/2)
        
        long long ans = (power(5, evenCount) * power(4, oddCount)) % MOD;
        return (int)ans;
    }
};
