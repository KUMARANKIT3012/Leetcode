class Solution {
public:
    int m, n;
    
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (row < 0 || col < 0 || row >= m || col >= n) return;
        if (visited[row][col] || board[row][col] != 'O') return;
        
        visited[row][col] = true;

        // 4 directions
        dfs(row + 1, col, board, visited);
        dfs(row - 1, col, board, visited);
        dfs(row, col + 1, board, visited);
        dfs(row, col - 1, board, visited);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Step 1: Mark safe 'O's on the border and connected to the border
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !visited[i][0]) dfs(i, 0, board, visited);
            if (board[i][n - 1] == 'O' && !visited[i][n - 1]) dfs(i, n - 1, board, visited);
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !visited[0][j]) dfs(0, j, board, visited);
            if (board[m - 1][j] == 'O' && !visited[m - 1][j]) dfs(m - 1, j, board, visited);
        }

        // Step 2: Flip all unvisited 'O's to 'X'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
