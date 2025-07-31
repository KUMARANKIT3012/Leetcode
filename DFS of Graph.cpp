class Solution {
  public:
    void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& result) {
        vis[node] = 1;             // Mark current node as visited
        result.push_back(node);   // Add to result

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsHelper(it, adj, vis, result);  // Recursively visit unvisited neighbors
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);     // Visited array
        vector<int> result;        // DFS traversal result

        dfsHelper(0, adj, vis, result);  // Start DFS from node 0
        return result;
    }
};
