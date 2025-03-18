class Solution {
public:
    // Function to compute XOR from 1 to n
    int computeXOR(int n) {
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;
        return 0;
    }

    // Function to compute XOR in range [l, r]
    int findXOR(int l, int r) {
        return computeXOR(r) ^ computeXOR(l - 1);
    }
};
