class Solution {
  public:
    long long power(long long base, int exp, int m) {
        long long result = 1;
        for (int i = 1; i <= exp; i++) {
            result *= base;
            if (result > m) return result; // Early stopping
        }
        return result;
    }

    int nthRoot(int n, int m) {
        int low = 1, high = m;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long pow = power(mid, n, m);
            
            if (pow == m)
                return mid;
            else if (pow < m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1; // No integer root found
    }
};
