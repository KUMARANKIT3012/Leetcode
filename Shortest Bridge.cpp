class Solution {
public:
    int n;
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int,int>> q;
    vector<vector<int>> vis;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= n || c >= n)
            return;

        if (grid[r][c] == 0 || vis[r][c])
            return;

        vis[r][c] = 1;
        q.push({r, c});

        for (auto d : dir)
            dfs(grid, r + d[0], c + d[1]);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vis.assign(n, vector<int>(n, 0));

        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    found = true;
                }
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= n || vis[nr][nc])
                        continue;

                    if (grid[nr][nc] == 1)
                        return ans;

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }

            ans++;
        }

        return -1;
    }
};
