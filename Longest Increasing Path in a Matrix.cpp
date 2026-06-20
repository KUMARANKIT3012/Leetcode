class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> dp;

    int dfs(int r, int c, int prevVal, vector<vector<int>>& matrix) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS ||
            matrix[r][c] <= prevVal) {
            return 0;
        }

        if (dp[r][c] != -1)
            return dp[r][c];

        int res = 1;

        res = max(res, 1 + dfs(r + 1, c, matrix[r][c], matrix));
        res = max(res, 1 + dfs(r - 1, c, matrix[r][c], matrix));
        res = max(res, 1 + dfs(r, c + 1, matrix[r][c], matrix));
        res = max(res, 1 + dfs(r, c - 1, matrix[r][c], matrix));

        dp[r][c] = res;
        return res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();

        dp.assign(ROWS, vector<int>(COLS, -1));

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(r, c, -1, matrix);
            }
        }

        int ans = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                ans = max(ans, dp[r][c]);
            }
        }

        return ans;
    }
};
