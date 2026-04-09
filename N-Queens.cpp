class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;

    unordered_set<int> col;      // column
    unordered_set<int> posDiag;  // r + c
    unordered_set<int> negDiag;  // r - c

    void backtrack(int r, int n) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            // check if safe
            if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c))
                continue;

            // place queen
            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1, n);

            // remove queen (backtrack)
            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        backtrack(0, n);
        return ans;
    }
};
