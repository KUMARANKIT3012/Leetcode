class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m, 1);
        int longest = 1;
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < j; i++) {
                bool valid = true;
                for(int row = 0; row < n; row++) {
                    if(strs[row][i] > strs[row][j]) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            longest = max(longest, dp[j]);
        }
        return m - longest;
    }
};
