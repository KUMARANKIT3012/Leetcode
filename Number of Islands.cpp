class Solution {
public:
    void bfs(int r, int c,
             vector<vector<char>>& grid,
             set<pair<int, int>>& visit,
             int rows, int cols) {
                
        queue<pair<int, int>> q;

        visit.insert({r, c});
        q.push({r, c});

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == '1' &&
                    !visit.count({nr, nc})) {

                    q.push({nr, nc});
                    visit.insert({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        set<pair<int, int>> visit;
        int islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1' &&
                    !visit.count({r, c})) {

                    bfs(r, c, grid, visit, rows, cols);
                    islands++;
                }
            }
        }

        return islands;
    }
};
