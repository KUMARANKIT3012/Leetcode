class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i) {
        int ROWS = board.size();
        int COLS = board[0].size();

        if (i == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != word[i]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, r + 1, c, i + 1) ||
                     dfs(board, word, r - 1, c, i + 1) ||
                     dfs(board, word, r, c + 1, i + 1) ||
                     dfs(board, word, r, c - 1, i + 1);

        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
