#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        // effort[x][y] = minimum effort required to reach (x, y)
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        
        // Min-heap: {currentEffort, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        effort[0][0] = 0;

        // Directions: up, right, down, left
        vector<int> dir = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int e = cur[0], x = cur[1], y = cur[2];

            // If we reached destination, return effort
            if (x == m - 1 && y == n - 1) return e;

            // Explore neighbors
            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k], ny = y + dir[k + 1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int nextEffort = max(e, abs(heights[nx][ny] - heights[x][y]));
                    if (nextEffort < effort[nx][ny]) {
                        effort[nx][ny] = nextEffort;
                        pq.push({nextEffort, nx, ny});
                    }
                }
            }
        }
        return 0; // should never reach here
    }
};
