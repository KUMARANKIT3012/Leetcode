class Solution {
public:
    int rows, cols;
    set<pair<int, int>> visit;
    
    bool dfs(int r, int c, vector<vector<int>>& grid1,
             vector<vector<int>>& grid2) {

        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            grid2[r][c] == 0 || visit.count({r, c})) {
            return true;
        }

        visit.insert({r, c});
        bool res = true;

        if (grid1[r][c] == 0) res = false;
        res = dfs(r - 1, c, grid1, grid2) && res;
        res = dfs(r + 1, c, grid1, grid2) && res;
        res = dfs(r, c - 1, grid1, grid2) && res;
        res = dfs(r, c + 1, grid1, grid2) && res;
        return res;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rows = grid1.size();
        cols = grid1[0].size();
        int count = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid2[r][c] && !visit.count({r, c}) && dfs(r, c, grid1, grid2)) {
                    count++;
                }
            }
        }
        return count;
    }
};
