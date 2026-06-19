class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int ROWS = rooms.size();
        int COLS = rooms[0].size();

        set<pair<int, int>> visit;
        queue<pair<int, int>> q;

        auto addRoom = [&](int r, int c) {
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS ||
                visit.count({r, c}) || rooms[r][c] == -1) {
                return;
            }

            visit.insert({r, c});
            q.push({r, c});
        };

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (rooms[r][c] == 0) {
                    q.push({r, c});
                    visit.insert({r, c});
                }
            }
        }

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                rooms[r][c] = dist;

                addRoom(r + 1, c);
                addRoom(r - 1, c);
                addRoom(r, c + 1);
                addRoom(r, c - 1);
            }

            dist++;
        }
    }
};
