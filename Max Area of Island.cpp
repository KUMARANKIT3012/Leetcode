class Solution {
public:
    int ROWS, COLS;
    set<pair<int, int>> visit;
    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == 0 || visit.count({r, c})) {
            return 0;
        }
        visit.insert({r, c});
        return 1 +
               dfs(r + 1, c, grid) +
               dfs(r - 1, c, grid) +
               dfs(r, c + 1, grid) +
               dfs(r, c - 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int area = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                area = max(area, dfs(r, c, grid));
            }
        }
        return area;
    }
};
