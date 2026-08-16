class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                set<int> s;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        s.insert(grid[x][y]);
                    }
                }
                if (s.size() == 1) {
                    ans[i][j] = 0;
                    continue;
                }
                int mini = INT_MAX;
                auto prev = s.begin();
                auto curr = next(s.begin());
                while (curr != s.end()) {
                    mini = min(mini, *curr - *prev);
                    prev = curr;
                    curr++;
                }
                ans[i][j] = mini;
            }
        }
        return ans;
    }
};
