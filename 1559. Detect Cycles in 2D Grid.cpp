class Solution {
public:
    int n, m;
    
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis,int r, int c, int pr, int pc) {
        vis[r][c] = 1;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            
            if (grid[nr][nc] != grid[r][c]) continue;
            
            if (!vis[nr][nc]) {
                if (dfs(grid, vis, nr, nc, r, c)) return true;
            }
            else if (nr != pr || nc != pc) {
                return true;
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, vis, i, j, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};
