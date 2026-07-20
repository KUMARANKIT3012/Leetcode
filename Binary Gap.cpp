class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int ans = 0;
        int pos = 0;

        while (n > 0) {
            if (n & 1) {
                if (prev != -1) {
                    ans = max(ans, pos - prev);
                }
                prev = pos;
            }
            pos++;
            n >>= 1;
        }

        return ans;
    }
};
