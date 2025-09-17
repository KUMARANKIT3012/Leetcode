class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // Precompute palindrome substrings
        vector<vector<int>> pal(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1]))
                    pal[i][j] = 1;
            }
        }

        vector<int> dp(n + 1, 0);
        dp[n] = -1; // after last index, aur cut ki zaroorat nahi hai

        for (int i = n - 1; i >= 0; i--) {
            int mini = INT_MAX;
            for (int j = i; j < n; j++) {
                if (pal[i][j]) {
                    mini = min(mini, 1 + dp[j + 1]);
                }
            }
            dp[i] = mini;
        }

        return dp[0];
    }
};
