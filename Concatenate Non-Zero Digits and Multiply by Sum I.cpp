class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long multiplier = 1;
        
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            
            if (digit != 0) {
                x += digit * multiplier;
                sum += digit;
                multiplier *= 10;
            }
        }
        
        return x * sum;
    }
};
