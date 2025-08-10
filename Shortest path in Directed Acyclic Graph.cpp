class Solution {
  public:
    void dfs(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                dfs(v, adj, vis, st);
            }
        }
        st.push(node); // push after visiting all children
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list (with weights)
        vector<pair<int,int>> adj[V];
        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Step 2: Topological sort using DFS
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfs(i, adj, vis, st);
        }

        // Step 3: Initialize distances
        vector<int> dist(V, 1e9);
        dist[0] = 0; // assuming src = 0

        // Step 4: Relax edges in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) { // only relax if node is reachable
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Step 5: Convert unreachable nodes to -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};
