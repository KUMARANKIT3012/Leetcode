class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minRow(n + 1, INT_MAX), maxRow(n + 1, INT_MIN);
        vector<int> minCol(n + 1, INT_MAX), maxCol(n + 1, INT_MIN);

        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            minRow[x] = min(minRow[x], y);
            maxRow[x] = max(maxRow[x], y);

            minCol[y] = min(minCol[y], x);
            maxCol[y] = max(maxCol[y], x);
        }

        int ans = 0;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            if (y > minRow[x] && y < maxRow[x] &&
                x > minCol[y] && x < maxCol[y]) {
                ans++;
            }
        }

        return ans;
    }
};
