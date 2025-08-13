class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Step 1: Initialize distances
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (auto &e : edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        // Step 2: Floyd–Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Step 3 & 4: Find the city with smallest reachable count
        int ansCity = -1;
        int minReachable = n; // max possible
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= minReachable) { 
                // tie-breaking: choose the larger index
                minReachable = count;
                ansCity = i;
            }
        }

        return ansCity;
    }
};
