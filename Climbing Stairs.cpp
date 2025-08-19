class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;  // base cases: 1 -> 1 way, 2 -> 2 ways

        int prev1 = 2;  // ways to reach step 2
        int prev2 = 1;  // ways to reach step 1
        int curr;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2; // recurrence relation
            prev2 = prev1;        // move forward
            prev1 = curr;
        }

        return curr;
    }
};
