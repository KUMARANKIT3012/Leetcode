class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        // Step 1: Push all boundary 1s to the queue and mark them visited
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1 && !visited[i][0]) {
                q.push({i, 0});
                visited[i][0] = true;
            }
            if (grid[i][n - 1] == 1 && !visited[i][n - 1]) {
                q.push({i, n - 1});
                visited[i][n - 1] = true;
            }
        }

        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1 && !visited[0][j]) {
                q.push({0, j});
                visited[0][j] = true;
            }
            if (grid[m - 1][j] == 1 && !visited[m - 1][j]) {
                q.push({m - 1, j});
                visited[m - 1][j] = true;
            }
        }

        // Directions: up, down, left, right
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // Step 2: BFS from all border 1s
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int newX = x + dx[dir];
                int newY = y + dy[dir];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    grid[newX][newY] == 1 && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }

        // Step 3: Count unvisited land cells (enclaves)
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j])
                    count++;
            }
        }

        return count;
    }
};
