class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        map<pair<int, int>, int> cnt;
        for (auto &c : coordinates) {
            int x = c[0], y = c[1];
            for (int dx = -1; dx <= 0; dx++) {
                for (int dy = -1; dy <= 0; dy++) {
                    int r = x + dx;
                    int col = y + dy;
                    if (r >= 0 && r < m - 1 && col >= 0 && col < n - 1) {
                        cnt[{r, col}]++;
                    }
                }
            }
        }
        vector<long long> ans(5, 0);
        for (auto &it : cnt) {
            ans[it.second]++;
        }
        long long totalBlocks = 1LL * (m - 1) * (n - 1);
        long long used = 0;
        for (int i = 1; i <= 4; i++) used += ans[i];
        ans[0] = totalBlocks - used;
        return ans;
    }
};
