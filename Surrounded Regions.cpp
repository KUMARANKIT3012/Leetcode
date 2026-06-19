class Solution {
public:
    int ROWS, COLS;
    void capture(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'T';
        capture(r + 1, c, board);
        capture(r - 1, c, board);
        capture(r, c + 1, board);
        capture(r, c - 1, board);
    }

    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        // 1. Capture unsurrounded regions (O -> T)
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O' && (r == 0 || r == ROWS - 1 ||
                    c == 0 || c == COLS - 1)) {
                    capture(r, c, board);
                }
            }
        }

        // 2. Capture surrounded regions (O -> X)
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
            }
        }

        // 3. Uncapture unsurrounded regions (T -> O)
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
};
