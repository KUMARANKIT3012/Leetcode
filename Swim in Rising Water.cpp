class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        set<pair<int, int>> visit;
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > minH;

        vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        minH.push({grid[0][0], 0, 0});   // {time, row, col}
        visit.insert({0, 0});
        while (!minH.empty()) {
            auto curr = minH.top();
            minH.pop();
            int t = curr[0];
            int r = curr[1];
            int c = curr[2];
            if (r == N - 1 && c == N - 1)
                return t;
            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= N || nc >= N ||
                    visit.count({nr, nc})) {
                    continue;
                }
                visit.insert({nr, nc});
                minH.push({
                    max(t, grid[nr][nc]), nr, nc
                });
            }
        }
        return -1;
    }
};
