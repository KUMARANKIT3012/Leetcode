class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int N = adj.size();
        vector<int> dist(N, 1e9); // initialize distances with a large value
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        // If a node is unreachable, mark it as -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};
