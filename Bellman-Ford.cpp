class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const int INF = 1e8; // large number for infinity
        vector<int> dist(V, INF);
        dist[src] = 0;

        // Step 2: Relax edges (V-1) times
        for (int i = 0; i < V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Step 3: Check for negative weight cycles (optional based on problem)
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                // Negative cycle detected
                return {-1};
            }
        }

        return dist;
    }
};
