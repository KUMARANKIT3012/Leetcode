class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid,
            vector<vector<bool>>& visit) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0)
            return 1;
        if (visit[i][j])
            return 0;
        visit[i][j] = true;
        int perim = 0;
        perim += dfs(i, j + 1, grid, visit);
        perim += dfs(i + 1, j, grid, visit);
        perim += dfs(i, j - 1, grid, visit);
        perim += dfs(i - 1, j, grid, visit);
        return perim;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j, grid, visit);
                }
            }
        }
        return 0;
    }
};
