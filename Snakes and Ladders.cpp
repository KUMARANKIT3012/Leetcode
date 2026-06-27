class Solution {
public:
    pair<int, int> getPos(int square, int n) {
        int r = (square - 1) / n;
        int c = (square - 1) % n;
        if (r % 2 == 1)
            c = n - 1 - c;
        r = n - 1 - r;
        return {r, c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<int> vis(n * n + 1, 0);
        vis[1] = 1;

        while (!q.empty()) {
            auto [square, moves] = q.front();
            q.pop();

            for (int i = 1; i <= 6 && square + i <= n * n; i++) {
                int nextSquare = square + i;
                auto [r, c] = getPos(nextSquare, n);
                if (board[r][c] != -1)
                    nextSquare = board[r][c];
                if (nextSquare == n * n)
                    return moves + 1;
                if (!vis[nextSquare]) {
                    vis[nextSquare] = 1;
                    q.push({nextSquare, moves + 1});
                }
            }
        }
        return -1;
    }
};
